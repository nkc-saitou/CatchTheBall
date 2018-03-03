using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace CatchTheBallTool {

	/// <summary>
	/// メインフォーム
	/// </summary>
	public partial class FormMain : Form {

		public static FormMain Instance { get; private set; }
		public static bool isEdit = false;

		public event Action StageLoaded;

		Dictionary<string, FormWindowBase> formWindowDictionary;

		public FormMain() {
			InitializeComponent();

			//初期化処理
			Init();
		}

		#region Initialize
		/// <summary>
		/// 初期化処理
		/// </summary>
		void Init() {

			//設定
			Instance = this;

			//拡張子に合わせて変更
			OpenFileStageData.DefaultExt = StageData.STAGE_DATA_EXT;
			SaveFileStageData.DefaultExt = StageData.STAGE_DATA_EXT;

			var filter = "ステージデータ|*." + StageData.STAGE_DATA_EXT;
			OpenFileStageData.Filter = filter;
			SaveFileStageData.Filter = filter;

			//デフォルトレイアウト読み込み
			LayoutInit();

			//コマンド系
			ResetCommand();
			CommandStream.Instance.ExecuteCommandEvent += () => {
				元に戻すUToolStripMenuItem.Enabled = CommandStream.Instance.CanUndo();
				やり直しRToolStripMenuItem.Enabled = CommandStream.Instance.CanRedo();
			};
			CommandStream.Instance.UndoCommandEvent += () => {
				元に戻すUToolStripMenuItem.Enabled = CommandStream.Instance.CanUndo();
				やり直しRToolStripMenuItem.Enabled = CommandStream.Instance.CanRedo();
			};
		}
		/// <summary>
		/// 各ウィンドウを初期化する
		/// </summary>
		void WindowInit() {

			if(formWindowDictionary != null) {
				foreach(var item in formWindowDictionary) {
					if(item.Value != null) item.Value.Dispose();
				}
			}

			formWindowDictionary = new Dictionary<string, FormWindowBase>();
		}
		/// <summary>
		/// レイアウトの初期設定
		/// </summary>
		void LayoutInit() {

			var path = SystemData.DEFAULT_LAYOUT_PATH;
			if(File.Exists(path)) {

				//デフォルトのレイアウトを適用
				LoadWindowLayout(path);
			}
			else {

				MessageBox.Show(
					"デフォルトレイアウトが見つかりませんでした",
					"デフォルトレイアウト読み込みエラー",
					MessageBoxButtons.OK,
					MessageBoxIcon.Error);

				//ウィンドウの初期化
				WindowInit();

				//各ウィンドウの追加
				foreach(var item in WindowDefinition.windowDictionary) {
					formWindowDictionary.Add(item.Key, item.Value(DockPanelMain));
				}

				var directory = SystemData.DEFAULT_LAYOUT_DIRECTORY;

				//ディレクトリがない場合は作成
				if(!Directory.Exists(directory)) Directory.CreateDirectory(directory);

				//とりあえず現状を保存
				SaveWindowLayout(path);
			}
		}
		void ResetCommand() {
			CommandStream.Instance.ClearCommand();
			元に戻すUToolStripMenuItem.Enabled = false;
			やり直しRToolStripMenuItem.Enabled = false;
		}
		#endregion

		#region Layout
		/// <summary>
		/// レイアウトを保存する
		/// </summary>
		/// <param name="path"></param>
		bool SaveWindowLayout(string path) {
			DockPanelMain.SaveAsXml(path);
			return true;
		}
		/// <summary>
		/// レイアウトを読み込んで適用する
		/// </summary>
		/// <param name="path"></param>
		bool LoadWindowLayout(string path) {

			//初期化しないとエラーになる
			WindowInit();

			//レイアウトの読み込み
			DockPanelMain.LoadFromXml(path, (string persistString) => {

				if(!WindowDefinition.windowDictionary.ContainsKey(persistString))
					return null;

				var window = WindowDefinition.windowDictionary[persistString](DockPanelMain);
				formWindowDictionary.Add(persistString, window);
				return window;
			});

			//生成していないものがあれば生成
			foreach(var item in WindowDefinition.windowDictionary) {
				if(!formWindowDictionary.ContainsKey(item.Key))
					formWindowDictionary.Add(item.Key, item.Value(DockPanelMain));

			}

			return true;
		}
		#endregion

		#region File
		/// <summary>
		/// ステージデータを新規作成する
		/// </summary>
		/// <returns></returns>
		bool NewFile() {
			if(SystemData.Instance.IsEdit) {
				//編集状態なので保存を促す
				switch(ShowEditFileClosingMessage()) {
					case DialogResult.Yes: if(SaveFile()) break; else return false;
					case DialogResult.No: break;
					default: return false;
				}
			}

			//新規作成
			if(new FormStageDataNew().ShowDialog() == DialogResult.OK) {

				//コマンド系をリセット
				ResetCommand();

				return true;
			}

			return false;
		}
		/// <summary>
		/// ステージデータを開く
		/// </summary>
		/// <returns></returns>
		bool OpenFile() {

			if(OpenFileStageData.ShowDialog() != DialogResult.OK) return false;
			if(!StageData.Instance.Import(FileIO.LoadFile(OpenFileStageData.FileName))) return false;

			//パスを保存
			StageData.Instance.StagePath = OpenFileStageData.FileName;
			Text = StageData.Instance.StageName = StageData.Instance.StagePath.GetFileName();

			//ロードイベント起動
			if(StageLoaded != null) StageLoaded();

			//コマンド系をリセット
			ResetCommand();

			return true;
		}
		/// <summary>
		/// ステージデータを上書き保存する
		/// </summary>
		/// <returns></returns>
		bool SaveFile() {

			if(StageData.Instance.StagePath == "") return SaveFileAs();
			if(!FileIO.SaveFile(StageData.Instance.StagePath, StageData.Instance.Export())) return false;

			//編集フラグを消す
			SystemData.Instance.IsEdit = false;

			return true;
		}
		/// <summary>
		/// ステージデータを別名で保存する
		/// </summary>
		/// <returns></returns>
		bool SaveFileAs() {

			if(SaveFileStageData.ShowDialog() != DialogResult.OK) return false;

			//パスを保存
			StageData.Instance.StagePath = SaveFileStageData.FileName;
			StageData.Instance.StageName = StageData.Instance.StagePath.GetFileName();

			return SaveFile();
		}
		bool SaveViewImage() {

			if(SaveFileView.ShowDialog() != DialogResult.OK) return false;

			//画像を保存
			SystemData.Instance.RenderView.Save(SaveFileView.FileName);

			return true;
		}
		#endregion

		#region Event
		private void FormMain_Load(object sender, EventArgs e) {

		}

		private void FormMain_FormClosing(object sender, FormClosingEventArgs e) {

			if(SystemData.Instance.IsEdit) {
				//編集状態なので保存を促す
				switch(ShowEditFileClosingMessage()) {
					case DialogResult.Yes: if(SaveFile()) break; break;
					case DialogResult.No: return;
					default: break;
				}

				e.Cancel = true;
			}
		}
		#endregion

		#region MenuBar

		#region File
		private void 新規ToolStripMenuItem_Click(object sender, EventArgs e) {
			NewFile();
		}
		private void 開くToolStripMenuItem_Click(object sender, EventArgs e) {
			OpenFile();
		}
		private void 上書き保存SToolStripMenuItem_Click(object sender, EventArgs e) {
			SaveFile();
		}
		private void 名前を付けて保存AToolStripMenuItem_Click(object sender, EventArgs e) {
			SaveFileAs();
		}
		private void 画像としてビューを保存ToolStripMenuItem_Click(object sender, EventArgs e) {
			SaveViewImage();
		}
		private void 閉じるXToolStripMenuItem_Click(object sender, EventArgs e) {
			Close();
		}
		#endregion

		#region Edit
		private void 元に戻すUToolStripMenuItem_Click(object sender, EventArgs e) {
			CommandStream.Instance.UndoCommand();
		}
		private void やり直しRToolStripMenuItem_Click(object sender, EventArgs e) {
			CommandStream.Instance.RedoCommand();
		}
		private void ステージデータの編集EToolStripMenuItem_Click(object sender, EventArgs e) {
			new FormStageDataEdit().ShowDialog();
		}
		#endregion

		#region Layout
		private void デフォルトレイアウトを復元ToolStripMenuItem_Click(object sender, EventArgs e) {
			LoadWindowLayout(SystemData.DEFAULT_LAYOUT_PATH);
		}
		private void ユーザーレイアウトの保存ToolStripMenuItem_Click(object sender, EventArgs e) {
			if(SaveLayoutDialog.ShowDialog() != DialogResult.OK) return;
			SaveWindowLayout(SaveLayoutDialog.FileName);
		}
		private void ユーザーレイアウトの読み込みToolStripMenuItem_Click(object sender, EventArgs e) {
			if(OpenLayoutDialog.ShowDialog() != DialogResult.OK) return;
			LoadWindowLayout(OpenLayoutDialog.FileName);
		}
		#endregion

		#region Help
		private void dockPanelSuiteToolStripMenuItem_Click(object sender, EventArgs e) {

			var stringBuilder = new StringBuilder();
			stringBuilder
				.Append("The MIT License\n\n")
				.Append("Copyright(c) 2007 Weifen Luo(email: weifenluo@yahoo.com)\n\n")
				.Append("Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files(the \"Software\"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and / or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:\n\n")
				.Append("The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.\n\n")
				.Append("THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\n");

			MessageBox.Show(stringBuilder.ToString(), "DockPanelSuite Licence", MessageBoxButtons.OK);

		}
		#endregion

		#endregion

		/// <summary>
		/// データ変更中に閉じるときに訊く
		/// </summary>
		/// <returns></returns>
		DialogResult ShowEditFileClosingMessage() {
			return MessageBox.Show("編集中のデータがあります。\n保存しますか?",
				"データ編集中警告",
				MessageBoxButtons.YesNoCancel);
		}

		public T GetWindow<T>() where T : FormWindowBase {

			var windowDict = Instance.formWindowDictionary;
			var key = typeof(T).ToString();

			if(!windowDict.ContainsKey(key)) return null;

			var instance = windowDict[key];
			return (T)instance;
			
		}
	}
}

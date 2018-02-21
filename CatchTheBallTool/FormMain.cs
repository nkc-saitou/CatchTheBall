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

		const string DEFAULT_LAYOUT_DIRECTORY = @"./Settings/";
		const string DEFAULT_LAYOUT_FILE = @"DefaultLayout.xml";

		static string defaultLayoutPath = DEFAULT_LAYOUT_DIRECTORY + DEFAULT_LAYOUT_FILE;

		public static FormMain instance;
		public static bool isEdit = false;

		Dictionary<string, FormWindowBase> formWindowDictionary;

		public FormMain() {
			InitializeComponent();

			//初期化処理
			Init();
		}

		/// <summary>
		/// 初期化処理
		/// </summary>
		void Init() {

			instance = this;

			//レイアウト
			if(File.Exists(defaultLayoutPath)) {

				//デフォルトのレイアウトを適用
				LoadWindowLayout(defaultLayoutPath);
			}
			else {
				MessageBox.Show(
					"デフォルトレイアウトが見つかりませんでした",
					"デフォルトレイアウト読み込みエラー",
					MessageBoxButtons.OK,
					MessageBoxIcon.Error);

				//ウィンドウの初期化
				WindowInit();

				if(!Directory.Exists(DEFAULT_LAYOUT_DIRECTORY)) Directory.CreateDirectory(DEFAULT_LAYOUT_DIRECTORY);
				SaveWindowLayout(defaultLayoutPath);
			}

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

			//各ウィンドウの追加
			formWindowDictionary.Add("FormView", new FormView(ビューVToolStripMenuItem));
			formWindowDictionary.Add("FormMapChip", new FormMapChip(マップチップMToolStripMenuItem));
			formWindowDictionary.Add("FormNavigation", new FormNavigation(ナビゲーションNToolStripMenuItem));

		}

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

				return formWindowDictionary.Values
				.Where(item => item != null)
				.FirstOrDefault(item => item.Text == persistString);
			});

			return true;
		}


		private void FormMain_Load(object sender, EventArgs e) {

		}

		#region MenuBar

		#region File

		private void 新規ToolStripMenuItem_Click(object sender, EventArgs e) {

		}
		private void 開くToolStripMenuItem_Click(object sender, EventArgs e) {

		}
		private void 上書き保存SToolStripMenuItem_Click(object sender, EventArgs e) {

		}
		private void 名前を付けて保存AToolStripMenuItem_Click(object sender, EventArgs e) {

		}
		private void 閉じるXToolStripMenuItem_Click(object sender, EventArgs e) {

		}

		#endregion

		#region Edit
		private void 元に戻すUToolStripMenuItem_Click(object sender, EventArgs e) {

		}
		private void やり直しRToolStripMenuItem_Click(object sender, EventArgs e) {

		}
		#endregion

		#region Window
		private void ビューVToolStripMenuItem_Click(object sender, EventArgs e) {
			formWindowDictionary["FormView"].Activate();
		}
		private void マップチップMToolStripMenuItem_Click(object sender, EventArgs e) {
			formWindowDictionary["FormMapChip"].Activate();
		}
		private void ナビゲーションNToolStripMenuItem_Click(object sender, EventArgs e) {
			formWindowDictionary["FormNavigation"].Activate();
		}
		#endregion

		#region Layout
		private void デフォルトレイアウトを復元ToolStripMenuItem_Click(object sender, EventArgs e) {
			LoadWindowLayout(defaultLayoutPath);
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
	}
}

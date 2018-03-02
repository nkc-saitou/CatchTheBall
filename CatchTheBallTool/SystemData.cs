using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace CatchTheBallTool {

	/// <summary>
	/// ツールが持っておきたいデータ
	/// </summary>
	public sealed class SystemData : Singleton<SystemData> {

		public const string DEFAULT_LAYOUT_DIRECTORY = @".\Settings\";
		public const string DEFAULT_LAYOUT_FILE = @"DefaultLayout.xml";
		public const string DEFAULT_LAYOUT_PATH = DEFAULT_LAYOUT_DIRECTORY + DEFAULT_LAYOUT_FILE;

		public const int CHIP_SIZE = 64;
		public const int CHIP_COUNT = 16;

		const string MAPCHIP_PATH = @".\image\MapChip.png";
		const string OBJECTCHIP_PATH = @".\image\ObjectChip.png";

		public Rectangle FocusRect { get; set; }
		public Image RenderView { get; set; }

		public ImageAtlas MapChip { get; private set; }
		public ImageAtlas ObjectChip { get; private set; }

		public int SelectChip { get; set; }

		public event Action<float> ViewMagnificationChanged;
		public event Action<DrawMode> DrawModeChanged;
		public event Action StageDraw;

		bool isEdit = false;
		public bool IsEdit {
			get { return isEdit; }
			set {
				if(isEdit == value) return;
				isEdit = value;

				FormMain.Instance.Text = StageData.Instance.StageName + (isEdit ? "*" : "");
			}
		}


		float viewMagnification = 1;
		public float ViewMagnification {
			get { return viewMagnification; }
			set {
				if(viewMagnification == value) return;

				viewMagnification = value;
				if(ViewMagnificationChanged != null) ViewMagnificationChanged(viewMagnification);
			}
		}


		public SystemData() { }

		protected override void Initialize() {
			base.Initialize();

			Load();
		}

		public void OnStageDraw() {
			if(StageDraw != null) StageDraw();
		}
		public void OnDrawModeChanged(DrawMode mode) {
			if(DrawModeChanged != null) DrawModeChanged(mode);
		}

		public void Load() {

			//マップチップの読み込み
			Image mapChip;
			if(File.Exists(MAPCHIP_PATH)) {
				mapChip = Image.FromFile(MAPCHIP_PATH);
			}
			else {
				MessageBox.Show("マップチップの存在が確認できませんでした");
				mapChip = new Bitmap(256, 256);
			}
			MapChip = new ImageAtlas(Image.FromFile(MAPCHIP_PATH), new Size(CHIP_SIZE, CHIP_SIZE));

			//オブジェクトチップの読み込み
			Image objectChip;
			if(File.Exists(OBJECTCHIP_PATH)) {
				objectChip = Image.FromFile(OBJECTCHIP_PATH);
			}
			else {
				MessageBox.Show("オブジェクトチップの存在が確認できませんでした");
				objectChip = new Bitmap(256, 256);
			}
			ObjectChip = new ImageAtlas(Image.FromFile(OBJECTCHIP_PATH), new Size(CHIP_SIZE, CHIP_SIZE));
		}
	}
}
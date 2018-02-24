using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.IO;

namespace CatchTheBallTool {

	/// <summary>
	/// ツールが持っておきたいデータ
	/// </summary>
	public sealed class SystemData : Singleton<SystemData> {

		public const string DEFAULT_LAYOUT_DIRECTORY = @".\Settings\";
		public const string DEFAULT_LAYOUT_FILE = @"DefaultLayout.xml";
		public const string DEFAULT_LAYOUT_PATH = DEFAULT_LAYOUT_DIRECTORY + DEFAULT_LAYOUT_FILE;

		public const int MAPCHIP_SIZE = 64;
		public const int MAPCHIP_COUNT = 16;

		const string DEFAULT_MAPCHIP_PATH = @"\image\DefaultMapChip.png";

		public string MapChipPath { get; set; }
		public ImageAtlas MapChip { get; set; }
		public Rectangle FocusRect { get; set; }
		public Image RenderView { get; set; }

		bool isEdit = false;
		public bool IsEdit {
			get { return isEdit; }
			set {
				if(isEdit == value) return;
				isEdit = value;

				FormMain.Instance.Text = StageData.Instance.StageName + (isEdit ? "*" : "");
			}
		}

		public SystemData() { }

		protected override void Initialize() {
			base.Initialize();

			MapChipPath = Directory.GetCurrentDirectory() + DEFAULT_MAPCHIP_PATH;

			Load();
		}

		public void Load() {
			MapChip = new ImageAtlas(Image.FromFile(MapChipPath), new Size(MAPCHIP_SIZE, MAPCHIP_SIZE));
		}

	}
}

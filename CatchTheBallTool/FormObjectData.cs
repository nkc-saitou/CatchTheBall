using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WeifenLuo.WinFormsUI.Docking;

namespace CatchTheBallTool {
	public partial class FormObjectData : FormWindowBase {

		readonly Color BACKGROUND_COLOR = Color.FromArgb(0xff, 0x00, 0x00, 0x00);

		const int MAX_OBJECT_DATA = 15;

		public FormObjectData(DockPanel dockPanel, ToolStripMenuItem item) : base(dockPanel, item) {
			InitializeComponent();

			Init();
			ObjectUpdate();

			//ステージデータが描画されたときに更新する
			SystemData.Instance.StageDraw += ObjectUpdate;
		}

		~FormObjectData() {

			//イベントの削除
			SystemData.Instance.StageDraw -= ObjectUpdate;

		}

		void Init() {

			Console.Write(DataGridObjectData.Rows.Count);

			//Rowを追加
			while(DataGridObjectData.Rows.Count < MAX_OBJECT_DATA) {
				DataGridObjectData.Rows.Add();
			}



			//番号と画像の設定
			for(int i = 0;i < MAX_OBJECT_DATA;i++) {
				DataGridObjectData.Rows[i].Cells[0].Value = i;

				var canvas = new Bitmap(SystemData.CHIP_SIZE, SystemData.CHIP_SIZE);
				var g = Graphics.FromImage(canvas);
				var brush = new SolidBrush(BACKGROUND_COLOR);

				g.FillRectangle(brush, new Rectangle(0, 0, SystemData.CHIP_SIZE, SystemData.CHIP_SIZE));
				g.DrawImage(SystemData.Instance.ObjectChip[i], new Point());

				DataGridObjectData.Rows[i].Cells[1].Value = canvas;

				g.Dispose();
			}

		}

		/// <summary>
		/// 各オブジェクトがいくつあるか調べる
		/// </summary>
		void ObjectUpdate() {

			if(DataGridObjectData.Rows.Count <= 0) return;

			var countData = new int[MAX_OBJECT_DATA];

			//各オブジェクトがいくつ存在しているか計算
			for(int i = 0;i < StageData.Instance.MapSize.Height;i++) {
				for(int j = 0;j < StageData.Instance.MapSize.Width;j++) {

					var data = StageData.Instance.ObjectMap[i][j];
					if(data < 0) continue;
					countData[data]++;
				}
			}

			//カウントを反映
			for(int i = 0;i < MAX_OBJECT_DATA;i++) {
				DataGridObjectData.Rows[i].Cells[2].Value = countData[i];
			}
		}
	}
}

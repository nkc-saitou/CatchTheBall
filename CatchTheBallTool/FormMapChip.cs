using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using WeifenLuo.WinFormsUI.Docking;

namespace CatchTheBallTool {

	/// <summary>
	/// マップチップを選択できるウィンドウ
	/// </summary>
	public partial class FormMapChip : FormWindowBase {

		readonly Color BACK_GROUND_COLOR = Color.FromArgb(0xff, 0x00, 0x00, 0x00);
		readonly Color SELECT_CHIP_COLOR = Color.FromArgb(0xff, 0xff, 0x00, 0x00);
		const float SELECT_CHIP_SIZE = 2;

		Rectangle drawRect;
		Size mapChipSize;

		public FormMapChip(DockPanel dockPanel, ToolStripMenuItem item) : base(dockPanel, item) {
			InitializeComponent();

			//マップチップ読み込み時にマップチップ描画
			SystemData.Instance.MapChipLoaded += Draw;

			//サイズ変更時に再計算
			DockStateChanged += (object sender, EventArgs e) => {
				CalcDrawRect();
			};
			PictureBoxView.SizeChanged += (object sender, EventArgs e) => {
				CalcDrawRect();
			};
		}

		~FormMapChip() {

			//イベントの削除
			SystemData.Instance.MapChipLoaded -= Draw;

		}

		/// <summary>
		/// マップチップの表示サイズを計算
		/// </summary>
		void CalcDrawRect() {

			var viewSize = PictureBoxView.Size;

			//描画後の画像を取得
			var mapChipImage = SystemData.Instance.MapChip.AtlasImage;

			//縦が1のときの横のサイズ
			var renderImageRatio = (float)mapChipImage.Size.Width / mapChipImage.Size.Height;
			var viewSizeRatio = (float)viewSize.Width / viewSize.Height;

			//描画位置・サイズを求める
			drawRect = new Rectangle();
			if(renderImageRatio > viewSizeRatio) {
				//横が最大
				drawRect.Size =
					new Size(viewSize.Width, (int)(viewSize.Width / renderImageRatio));
				drawRect.Location = new Point(0, (viewSize.Height - drawRect.Size.Height) / 2);
			}
			else {
				//縦が最大
				drawRect.Size =
					new Size((int)(viewSize.Height * renderImageRatio), viewSize.Height);
				drawRect.Location = new Point((viewSize.Width - drawRect.Size.Width) / 2, 0);
			}

			//1つのチップのサイズを計算しておく
			var mapChip = SystemData.Instance.MapChip;

			mapChipSize = new Size(
				drawRect.Size.Width / mapChip.ChipCount.Width,
				drawRect.Size.Height / mapChip.ChipCount.Height);

			Draw();
		}

		/// <summary>
		/// 描画する
		/// </summary>
		void Draw() {

			//初期設定
			var canvas = new Bitmap(PictureBoxView.Size.Width, PictureBoxView.Size.Height);
			var g = Graphics.FromImage(canvas);
			var brush = new SolidBrush(BACK_GROUND_COLOR);

			PictureBoxView.SuspendLayout();

			//背景を描画
			g.FillRectangle(brush, drawRect);
			//マップチップを描画
			g.DrawImage(SystemData.Instance.MapChip.AtlasImage, drawRect);
			//選択を描画
			//g.draw

			PictureBoxView.Image = canvas;
			PictureBoxView.ResumeLayout();

			//解放
			g.Dispose();
			brush.Dispose();
		}
	}
}

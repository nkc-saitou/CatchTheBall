﻿using System;
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
		const float SELECT_CHIP_PENSIZE = 5;

		Rectangle drawRect;
		Size drawChipSize;

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
			var renderImageAspect = (float)mapChipImage.Size.Width / mapChipImage.Size.Height;
			var viewSizeAspect = (float)viewSize.Width / viewSize.Height;

			//描画位置・サイズを求める
			drawRect = new Rectangle();
			if(renderImageAspect > viewSizeAspect) {
				//横が最大
				drawRect.Size =
					new Size(viewSize.Width, (int)(viewSize.Width / renderImageAspect));
				drawRect.Location = new Point(0, (viewSize.Height - drawRect.Size.Height) / 2);
			}
			else {
				//縦が最大
				drawRect.Size =
					new Size((int)(viewSize.Height * renderImageAspect), viewSize.Height);
				drawRect.Location = new Point((viewSize.Width - drawRect.Size.Width) / 2, 0);
			}

			//1つのチップのサイズを計算しておく
			var mapChip = SystemData.Instance.MapChip;
			drawChipSize = new Size(
				drawRect.Size.Width / mapChip.ChipCount.Width,
				drawRect.Size.Height / mapChip.ChipCount.Height);

			Draw();
		}

		/// <summary>
		/// マップチップを選択する
		/// </summary>
		/// <param name="position">MapChip上のマウス位置</param>
		void SelectMapChip(Point position) {

			var chipCount = SystemData.Instance.MapChip.ChipCount;

			var selectPoint = new Point(
				(int)((float)position.X / drawRect.Width * chipCount.Width),
				(int)((float)position.Y / drawRect.Height * chipCount.Height));

			SystemData.Instance.SelectMapChip = selectPoint.X + chipCount.Width * selectPoint.Y;
			
			Draw();
		}

		/// <summary>
		/// 描画する
		/// </summary>
		void Draw() {

			//初期設定
			var canvas = new Bitmap(PictureBoxView.Size.Width, PictureBoxView.Size.Height);
			var g = Graphics.FromImage(canvas);

			PictureBoxView.SuspendLayout();

			//背景を描画
			var brush = new SolidBrush(BACK_GROUND_COLOR);
			g.FillRectangle(brush, drawRect);
			brush.Dispose();

			//マップチップを描画
			g.DrawImage(SystemData.Instance.MapChip.AtlasImage, drawRect);

			//選択を描画
			var pen = new Pen(SELECT_CHIP_COLOR, SELECT_CHIP_PENSIZE);
			var mapChipRect = SystemData.Instance.MapChip.GetRectangleFromID(SystemData.Instance.SelectMapChip);

			var selectPoint = new Point(
				drawRect.X + (int)((float)mapChipRect.X / mapChipRect.Width * drawChipSize.Width),
				drawRect.Y + (int)((float)mapChipRect.Y / mapChipRect.Height * drawChipSize.Height));

			g.DrawRectangle(pen, new Rectangle(selectPoint, drawChipSize));
			pen.Dispose();

			PictureBoxView.Image = canvas;
			PictureBoxView.ResumeLayout();

			//解放
			g.Dispose();
		}

		#region Event
		private void PictureBoxView_MouseDown(object sender, MouseEventArgs e) {

			//マップチップ上を選択していなかったら終了
			if(!drawRect.Contains(e.X, e.Y)) return;

			//マップチップを選択
			SelectMapChip(new Point(e.X - drawRect.X, e.Y - drawRect.Y));
		}
		#endregion


	}
}

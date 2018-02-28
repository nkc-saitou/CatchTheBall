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
using CatchTheBallTool.Commnad;
using CatchTheBallTool.DrawTool;

namespace CatchTheBallTool {

	public enum DrawMode {
		Preview,
		MapChip,
		Object
	}

	/// <summary>
	/// ステージを編集するウィンドウ
	/// </summary>
	public partial class FormView : FormResizableWindow {

		readonly Color BACK_GROUND_COLOR = Color.FromArgb(0xff, 0x00, 0x00, 0x00);
		readonly Color FADE_MASK_COLOR = Color.FromArgb(0x55, 0x00, 0x00, 0x00);
		readonly Color LINE_COLOR = Color.FromArgb(0xff, 0x88, 0x88, 0x88);
		const float LINE_SIZE = 1;

		Rectangle drawRect;

		DrawMode mode;
		PictureBox currentDraw;

		Point prevMousePosition;
		MouseButtons clickButton;

		public FormView(DockPanel dockPanel, ToolStripMenuItem item) : base(dockPanel, item) {
			InitializeComponent();

			drawRect = new Rectangle();
			CalcDrawSize();

			ChangeViewMode(DrawMode.Preview);

			//ステージ読み込み時に描画
			FormMain.Instance.StageLoaded += Draw;
			//サイズ変更時に自分も変更
			SystemData.Instance.ViewMagnificationChanged += ViewMagnificationChanged;

			//マップサイズ変更時に再計算
		}

		~FormView() {

			//イベントの削除
			FormMain.Instance.StageLoaded -= Draw;
			SystemData.Instance.ViewMagnificationChanged -= ViewMagnificationChanged;
		}

		void CalcDrawSize() {
			drawRect.Size = new Size(
				StageData.Instance.MapSize.Width * SystemData.MAPCHIP_SIZE,
				StageData.Instance.MapSize.Height * SystemData.MAPCHIP_SIZE);
		}

		#region Draw
		/// <summary>
		/// 現在のステージデータを描画する
		/// </summary>
		public void Draw() {

			var renderCanvas = new Bitmap(drawRect.Size.Width, drawRect.Size.Height);
			var render = Graphics.FromImage(renderCanvas);

			currentDraw.SuspendLayout();

			//背景の描画
			DrawAll(render, BACK_GROUND_COLOR);
			//ステージの描画
			DrawStage(render);

			switch(mode) {
				case DrawMode.Preview:
					break;
				case DrawMode.MapChip:
					DrawLine(render);
					break;
				case DrawMode.Object:
					//ステージを暗くする
					DrawAll(render, FADE_MASK_COLOR);
					DrawLine(render);
					break;
				default:
					break;
			}

			//描画を保存
			SystemData.Instance.RenderView = renderCanvas;

			//サイズを調整して表示
			var viewSize = new Size(
				(int)(drawRect.Size.Width * CurrentSize), 
				(int)(drawRect.Size.Height * CurrentSize));

			currentDraw.Size = viewSize;

			var viewCanvas = new Bitmap(viewSize.Width, viewSize.Height);
			var g = Graphics.FromImage(viewCanvas);

			g.DrawImage(renderCanvas, new RectangleF(drawRect.Location.X, drawRect.Location.Y, viewSize.Width, viewSize.Height));
			currentDraw.Image = viewCanvas;

			currentDraw.ResumeLayout();

			//Drawイベント発火
			SystemData.Instance.OnStageDraw();

			//解放
			g.Dispose();
			render.Dispose();

		}
		/// <summary>
		/// 描画範囲を一色描画する
		/// </summary>
		/// <param name="g"></param>
		/// <param name="color"></param>
		void DrawAll(Graphics g, Color color) {

			var brush = new SolidBrush(color);
			g.FillRectangle(brush, 0, 0, drawRect.Size.Width, drawRect.Size.Height);

			brush.Dispose();
		}
		void DrawLine(Graphics g) {

			var pen = new Pen(LINE_COLOR, LINE_SIZE);

			for(int i = 0;i < StageData.Instance.MapSize.Width;i++) {
				g.DrawLine(pen, i * SystemData.MAPCHIP_SIZE, 0, i * SystemData.MAPCHIP_SIZE, drawRect.Size.Height);
			}
			for(int i = 0;i < StageData.Instance.MapSize.Height;i++) {
				g.DrawLine(pen, 0, i * SystemData.MAPCHIP_SIZE, drawRect.Size.Width, i * SystemData.MAPCHIP_SIZE);
			}

			pen.Dispose();
		}
		void DrawStage(Graphics g) {

			var map = StageData.Instance.Map;
			var size = StageData.Instance.MapSize;

			for(int i = 0;i < size.Height;i++) {
				for(int j = 0;j < size.Width;j++) {

					var chip = map[i][j];
					if(chip < 0 || chip >= SystemData.MAPCHIP_COUNT) continue;

					var position = new Point(j * SystemData.MAPCHIP_SIZE, i * SystemData.MAPCHIP_SIZE);
					g.DrawImage(SystemData.Instance.MapChip[chip], position);

				}
			}

		}
		#endregion

		/// <summary>
		/// スクロールする
		/// </summary>
		/// <param name="deltaPosition"></param>
		void ScrollPage(Point deltaPosition) {

			var page = GetPageFromMode(mode);

			page.AutoScrollPosition = new Point(
				page.AutoScrollPosition.X + deltaPosition.X,
				page.AutoScrollPosition.X + deltaPosition.Y);

		}

		public Point CalcMapPosition(Point mousePosition) {
			var mapPosition = new PointF(
				(mousePosition.X + drawRect.Location.X) / CurrentSize,
				(mousePosition.Y + drawRect.Location.Y) / CurrentSize);

			return new Point(
				(int)(mapPosition.X / drawRect.Width * StageData.Instance.MapSize.Width),
				(int)(mapPosition.Y / drawRect.Height * StageData.Instance.MapSize.Height));
		}

		#region Mouse
		/// <summary>
		/// マウスが押されたときの共通処理
		/// </summary>
		/// <param name="viewMousePosition"></param>
		/// <param name="button"></param>
		new void MouseDown(Point viewMousePosition, MouseButtons button) {

			if(clickButton != MouseButtons.None) return;

			prevMousePosition = MousePosition;
			clickButton = button;
		}
		/// <summary>
		/// マウスが動いた時の共通処理
		/// </summary>
		/// <param name="viewMousePosition"></param>
		new void MouseMove(Point viewMousePosition) {

			switch(clickButton) {
				case MouseButtons.Left:
					break;
				case MouseButtons.Right:
					break;
				case MouseButtons.Middle:

					//マウス移動に合わせてスクロール
					var page = GetPageFromMode(mode);
					var delta = new Point(
						MousePosition.X - prevMousePosition.X,
						MousePosition.Y - prevMousePosition.Y);

					Console.WriteLine(delta);

					page.AutoScrollPosition = new Point(
						Math.Abs(page.AutoScrollPosition.X) - delta.X,
						Math.Abs(page.AutoScrollPosition.Y) - delta.Y);

					break;
				default:
					break;
			}

			prevMousePosition = MousePosition;

		}
		/// <summary>
		/// マウスが離されたときの共通処理
		/// </summary>
		/// <param name="viewMousePosition"></param>
		/// <param name="button"></param>
		new void MouseUp(Point viewMousePosition, MouseButtons button) {

			if(clickButton != button) return;

			prevMousePosition = MousePosition;
			clickButton = MouseButtons.None;
		}
		#endregion

		/// <summary>
		/// 描画モードを変更する
		/// </summary>
		/// <param name="mode"></param>
		public void ChangeViewMode(DrawMode mode) {

			this.mode = mode;

			//描画対象を変更
			switch(mode) {
				case DrawMode.Preview:
					currentDraw = PictureBoxPreview;
					break;
				case DrawMode.MapChip:
					currentDraw = PictureBoxMapChip;
					break;
				case DrawMode.Object:
					currentDraw = PictureBoxObject;
					break;
				default:
					break;
			}
			Draw();
		}

		/// <summary>
		/// DrawModeからPageを取得する
		/// </summary>
		/// <param name="mode"></param>
		/// <returns></returns>
		TabPage GetPageFromMode(DrawMode mode) {
			switch(mode) {
				case DrawMode.Preview:
					return TabPreview;
				case DrawMode.MapChip:
					return TabMapping;
				case DrawMode.Object:
					return TabObject;
				default:
					return null;
			}
		}

		void ViewMagnificationChanged(float viewMaginification) {
			Draw();
		}

		#region Event
		private void FormView_Load(object sender, EventArgs e) {

		}
		private void FormView_SizeChanged(object sender, EventArgs e) {
			//Draw();
		}

		private void TabControlView_SelectedIndexChanged(object sender, EventArgs e) {

			var scrollPosition = GetPageFromMode(mode).AutoScrollPosition;

			//描画モード切り替え
			ChangeViewMode((DrawMode)TabControlView.SelectedIndex);

			//スクロール位置を反映
			TabControlView.SelectedTab.AutoScrollPosition =
				new Point(Math.Abs(scrollPosition.X), Math.Abs(scrollPosition.Y));

		}

		private void PictureBoxPreview_MouseDown(object sender, MouseEventArgs e) {
			MouseDown(e.Location, e.Button);
		}
		private void PictureBoxPreview_MouseMove(object sender, MouseEventArgs e) {
			MouseMove(e.Location);
		}
		private void PictureBoxPreview_MouseUp(object sender, MouseEventArgs e) {
			MouseUp(e.Location, e.Button);
		}

		private void PictureBoxMapChip_MouseDown(object sender, MouseEventArgs e) {

			FormTool.selectedTool.MouseDown(this, e.Location, e.Button);

			MouseDown(e.Location, e.Button);
		}
		private void PictureBoxMapChip_MouseMove(object sender, MouseEventArgs e) {

			FormTool.selectedTool.MouseMove(this, e.Location, e.Button);

			MouseMove(e.Location);
		}
		private void PictureBoxMapChip_MouseUp(object sender, MouseEventArgs e) {

			FormTool.selectedTool.MouseUp(this, e.Location, e.Button);

			MouseUp(e.Location, e.Button);
		}

		private void PictureBoxObject_MouseDown(object sender, MouseEventArgs e) {
			MouseDown(e.Location, e.Button);
		}
		private void PictureBoxObject_MouseMove(object sender, MouseEventArgs e) {
			MouseMove(e.Location);
		}
		private void PictureBoxObject_MouseUp(object sender, MouseEventArgs e) {
			MouseUp(e.Location, e.Button);
		}
		#endregion
	}
}

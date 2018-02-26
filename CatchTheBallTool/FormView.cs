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

		PointF position;

		DrawMode mode;
		PictureBox currentDraw;

		Size DrawSize {
			get {
				return new Size(
					StageData.Instance.MapSize.Width * SystemData.MAPCHIP_SIZE,
					StageData.Instance.MapSize.Height * SystemData.MAPCHIP_SIZE);
			}
		}

		public FormView(DockPanel dockPanel, ToolStripMenuItem item) : base(dockPanel, item) {
			InitializeComponent();

			ChangeViewMode(DrawMode.Preview);

			//ステージ読み込み時に描画
			FormMain.Instance.StageLoaded += Draw;
			//サイズ変更時に自分も変更
			SystemData.Instance.ViewMagnificationChanged += ViewMagnificationChanged;

		}

		~FormView() {

			//イベントの削除
			FormMain.Instance.StageLoaded -= Draw;
			SystemData.Instance.ViewMagnificationChanged -= ViewMagnificationChanged;
		}

		#region Draw
		/// <summary>
		/// 現在のステージデータを描画する
		/// </summary>
		void Draw() {

			//初期設定
			var drawSize = DrawSize;

			var renderCanvas = new Bitmap(drawSize.Width, drawSize.Height);
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
			var viewSize = new SizeF(drawSize.Width * CurrentSize, drawSize.Height * CurrentSize);
			var viewCanvas = new Bitmap((int)viewSize.Width, (int)viewSize.Height);
			var g = Graphics.FromImage(viewCanvas);

			g.DrawImage(renderCanvas, new RectangleF(position.X, position.Y, viewSize.Width, viewSize.Height));
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

			var drawSize = DrawSize;

			var brush = new SolidBrush(color);
			g.FillRectangle(brush, 0, 0, drawSize.Width, drawSize.Height);

			brush.Dispose();
		}
		void DrawLine(Graphics g) {

			var drawSize = DrawSize;
			var pen = new Pen(LINE_COLOR, LINE_SIZE);

			for(int i = 0;i < StageData.Instance.MapSize.Width;i++) {
				g.DrawLine(pen, i * SystemData.MAPCHIP_SIZE, 0, i * SystemData.MAPCHIP_SIZE, drawSize.Height);
			}
			for(int i = 0;i < StageData.Instance.MapSize.Height;i++) {
				g.DrawLine(pen, 0, i * SystemData.MAPCHIP_SIZE, drawSize.Width, i * SystemData.MAPCHIP_SIZE);
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
			//描画モード切り替え
			ChangeViewMode((DrawMode)TabControlView.SelectedIndex);
		}
		#endregion

	}
}

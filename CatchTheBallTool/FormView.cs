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
	/// ステージを編集するフォーム
	/// </summary>
	public partial class FormView : FormResizableWindow {

		readonly Color BACK_GROUND_COLOR = Color.FromArgb(0xff, 0x00, 0x00, 0x00);
		readonly Color FADE_MASK_COLOR = Color.FromArgb(0x55, 0x00, 0x00, 0x00);
		readonly Color LINE_COLOR = Color.FromArgb(0xff, 0x88, 0x88, 0x88);
		const float LINE_SIZE = 1;

		PictureBox PictureBoxPreview;
		PictureBox PictureBoxMapChip;
		PictureBox PictureBoxObject;

		Rectangle drawRect;

		DrawMode mode;
		PictureBox currentDraw;

		Point prevMousePosition;
		MouseButtons clickButton;

		public FormView(DockPanel dockPanel, ToolStripMenuItem item) : base(dockPanel, item) {
			InitializeComponent();

			drawRect = new Rectangle();

			AddPictureBox();
			CalcDrawSize();
			ChangeDrawMode(DrawMode.Preview);

			//ステージ読み込み時に描画
			FormMain.Instance.StageLoaded += Draw;
			//サイズ変更時に自分も変更
			SystemData.Instance.ViewMagnificationChanged += ViewMagnificationChanged;

			//マップサイズ変更時に再計算
			StageData.Instance.MapSizeChanged += CalcDrawSize;
		}

		~FormView() {

			//イベントの削除
			FormMain.Instance.StageLoaded -= Draw;
			SystemData.Instance.ViewMagnificationChanged -= ViewMagnificationChanged;
			StageData.Instance.MapSizeChanged -= CalcDrawSize;
		}

		void CalcDrawSize() {
			drawRect.Size = new Size(
				StageData.Instance.MapSize.Width * SystemData.CHIP_SIZE,
				StageData.Instance.MapSize.Height * SystemData.CHIP_SIZE);
		}

		/// <summary>
		/// 
		/// </summary>
		void AddPictureBox() {

			var panelPreview = new PanelMouseWheelDisable();
			TabPreview.Controls.Add(panelPreview);
			panelPreview.Dock = DockStyle.Fill;
			panelPreview.AutoScroll = true;

			PictureBoxPreview = new PictureBox();
			panelPreview.Controls.Add(PictureBoxPreview);
			PictureBoxPreview.MouseDown += PictureBoxPreview_MouseDown;
			PictureBoxPreview.MouseMove += PictureBoxPreview_MouseMove;
			PictureBoxPreview.MouseUp += PictureBoxPreview_MouseUp;
			PictureBoxPreview.MouseWheel += OnMouseWheel;


			var panelMapping = new PanelMouseWheelDisable();
			TabMapping.Controls.Add(panelMapping);
			panelMapping.Dock = DockStyle.Fill;
			panelMapping.AutoScroll = true;

			PictureBoxMapChip = new PictureBox();
			panelMapping.Controls.Add(PictureBoxMapChip);
			PictureBoxMapChip.MouseDown += PictureBoxMapChip_MouseDown;
			PictureBoxMapChip.MouseMove += PictureBoxMapChip_MouseMove;
			PictureBoxMapChip.MouseUp += PictureBoxMapChip_MouseUp;
			PictureBoxMapChip.MouseWheel += OnMouseWheel;


			var panelObject = new PanelMouseWheelDisable();
			TabObject.Controls.Add(panelObject);
			panelObject.Dock = DockStyle.Fill;
			panelObject.AutoScroll = true;

			PictureBoxObject = new PictureBox();
			panelObject.Controls.Add(PictureBoxObject);
			PictureBoxObject.MouseDown += PictureBoxObject_MouseDown;
			PictureBoxObject.MouseMove += PictureBoxObject_MouseMove;
			PictureBoxObject.MouseUp += PictureBoxObject_MouseUp;
			PictureBoxObject.MouseWheel += OnMouseWheel;
		}

		#region Draw
		/// <summary>
		/// 現在のステージデータを描画する
		/// </summary>
		public void Draw() {

			var renderCanvas = new Bitmap(drawRect.Size.Width, drawRect.Size.Height);
			var render = Graphics.FromImage(renderCanvas);

			currentDraw.SuspendLayout();

			//プレビューを描画
			DrawPreview();

			switch(mode) {
				case DrawMode.Preview:
					//保存データから持ってくる
					render.DrawImage(SystemData.Instance.RenderView, new PointF());
					break;
				case DrawMode.MapChip:
					//背景の描画
					DrawBackGround(render);
					//ステージの描画
					DrawStage(render);
					DrawLine(render);
					break;
				case DrawMode.Object:
					//背景の描画
					DrawBackGround(render);
					//ステージの描画
					DrawStage(render);
					//ステージを暗くする
					DrawAll(render, FADE_MASK_COLOR);
					//オブジェクトの描画
					DrawObject(render);
					DrawLine(render);
					break;
				default:
					break;
			}

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
		/// プレビューを描画する
		/// </summary>
		void DrawPreview() {

			var renderCanvas = new Bitmap(drawRect.Size.Width, drawRect.Size.Height);
			var render = Graphics.FromImage(renderCanvas);

			//背景の描画
			DrawBackGround(render);
			//ステージの描画
			DrawStage(render);
			//オブジェクトの描画
			DrawObject(render);

			//描画を保存
			SystemData.Instance.RenderView = renderCanvas;

		}
		//背景を描画する
		void DrawBackGround(Graphics g) {

			var bgImage = SystemData.Instance.BackgroundImage;
			var aspect = (float)bgImage.Width / bgImage.Height;
			//表示サイズを計算しておく
			var drawSize = new SizeF(drawRect.Size.Height * aspect, drawRect.Size.Height);

			//途切れそうになるまで描画し続ける
			var currentX = 0;
			while(currentX + drawSize.Width < drawRect.Width) {
				var rect = new RectangleF(new PointF(currentX, 0), drawSize);
				currentX += (int)drawSize.Width;

				g.DrawImage(bgImage, rect);
			}

			//残りの部分を計算して描画する
			var destRect = new RectangleF(currentX, 0, drawRect.Width - currentX, drawRect.Height);
			var srcRect = new RectangleF(0, 0, destRect.Size.Height / bgImage.Height, bgImage.Height);

			g.DrawImage(bgImage, destRect, srcRect, GraphicsUnit.Pixel);
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
		/// <summary>
		/// 枠線を描画する
		/// </summary>
		/// <param name="g"></param>
		void DrawLine(Graphics g) {

			var pen = new Pen(LINE_COLOR, LINE_SIZE);

			for(int i = 0;i < StageData.Instance.MapSize.Width;i++) {
				g.DrawLine(pen, i * SystemData.CHIP_SIZE, 0, i * SystemData.CHIP_SIZE, drawRect.Size.Height);
			}
			for(int i = 0;i < StageData.Instance.MapSize.Height;i++) {
				g.DrawLine(pen, 0, i * SystemData.CHIP_SIZE, drawRect.Size.Width, i * SystemData.CHIP_SIZE);
			}

			pen.Dispose();
		}
		/// <summary>
		/// ステージを描画する
		/// </summary>
		/// <param name="g"></param>
		void DrawStage(Graphics g) {

			var map = StageData.Instance.StageMap;
			var size = StageData.Instance.MapSize;

			for(int i = 0;i < size.Height;i++) {
				for(int j = 0;j < size.Width;j++) {

					var chip = map[i][j];
					if(chip < 0 || chip >= SystemData.CHIP_COUNT) continue;

					var position = new Point(j * SystemData.CHIP_SIZE, i * SystemData.CHIP_SIZE);
					g.DrawImage(SystemData.Instance.MapChip[chip], position);

				}
			}

		}
		/// <summary>
		/// オブジェクトを描画する
		/// </summary>
		/// <param name="g"></param>
		void DrawObject(Graphics g) {

			var map = StageData.Instance.ObjectMap;
			var size = StageData.Instance.MapSize;

			for(int i = 0;i < size.Height;i++) {
				for(int j = 0;j < size.Width;j++) {

					var chip = map[i][j];
					if(chip < 0 || chip >= SystemData.CHIP_COUNT) continue;

					var position = new Point(j * SystemData.CHIP_SIZE, i * SystemData.CHIP_SIZE);
					g.DrawImage(SystemData.Instance.ObjectChip[chip], position);

				}
			}
		}
		#endregion

		/// <summary>
		/// マウスの位置からマップの位置を計算する
		/// </summary>
		/// <param name="mousePosition"></param>
		/// <returns></returns>
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
		public void ChangeDrawMode(DrawMode mode) {

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

			SystemData.Instance.OnDrawModeChanged(mode);

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
			ChangeDrawMode((DrawMode)TabControlView.SelectedIndex);

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

			var stagePosition = CalcMapPosition(e.Location);

			if(!StageData.Instance.CheckInsideMap(stagePosition)) return;

			//オブジェクトを配置
			switch(e.Button) {
				case MouseButtons.Left:
					if(StageData.Instance.ObjectMap[stagePosition.Y][stagePosition.X] == SystemData.Instance.SelectChip) return;
					CommandStream.Instance.ExecuteCommand(
						new CommandSetChip(StageData.Instance.ObjectMap, stagePosition, SystemData.Instance.SelectChip));
					break;
				case MouseButtons.Right:
					if(StageData.Instance.ObjectMap[stagePosition.Y][stagePosition.X] == -1) return;
					CommandStream.Instance.ExecuteCommand(
						new CommandSetChip(StageData.Instance.ObjectMap, stagePosition, -1));
					break;
				default:
					break;
			}


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

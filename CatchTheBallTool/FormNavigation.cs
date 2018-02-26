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

	/// <summary>
	/// 全体を表示するウィンドウ
	/// </summary>
	public partial class FormNavigation : FormResizableWindow {

		Rectangle drawRect;

		public FormNavigation(DockPanel dockPanel, ToolStripMenuItem item) : base(dockPanel, item) {
			InitializeComponent();

			drawRect = new Rectangle();

			//描画のタイミングで自身も描画する
			SystemData.Instance.StageDraw += Draw;

			//ファイルロード時に再計算
			FormMain.Instance.StageLoaded += CalcDrawRect;

			//ステージサイズ変更時に再計算

			//サイズ変更時に再計算
			DockStateChanged += (object sender, EventArgs e) => {
				CalcDrawRect();
			};
			PictureBoxView.SizeChanged += (object sender, EventArgs e) => {
				CalcDrawRect();
			};


			CalcDrawRect();
		}

		~FormNavigation() {

			//イベントの削除
			SystemData.Instance.StageDraw -= Draw;
			FormMain.Instance.StageLoaded -= CalcDrawRect;

		}

		void CalcDrawRect() {

			var viewSize = PictureBoxView.Size;

			//描画後の画像を取得
			var renderImage = SystemData.Instance.RenderView;

			//縦が1のときの横のサイズ
			var renderImageRatio = (float)renderImage.Size.Width / renderImage.Size.Height;
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

			Console.WriteLine(drawRect);

			Draw();
		}

		void Draw() {

			//初期設定
			var canvas = new Bitmap(PictureBoxView.Size.Width, PictureBoxView.Size.Height);
			var g = Graphics.FromImage(canvas);

			PictureBoxView.SuspendLayout();

			g.DrawImage(SystemData.Instance.RenderView, drawRect);
			PictureBoxView.Image = canvas;

			PictureBoxView.ResumeLayout();

			//解放
			g.Dispose();

		}
	}
}

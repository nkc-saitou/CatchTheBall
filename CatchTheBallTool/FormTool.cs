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
using CatchTheBallTool.DrawTool;

namespace CatchTheBallTool {

	/// <summary>
	/// 描画ツールを選択できるフォーム
	/// </summary>
	public partial class FormTool : FormWindowBase {

		readonly Point BUTTON_STARTPOSITION = new Point(6, 6);
		readonly Color BACKGROUND_COLOR = Color.White;
		readonly Color SELECTED_COLOR = Color.Gray;

		public static IDrawTool selectedTool;

		static Dictionary<string, IDrawTool> toolDictionary;

		const int BUTTON_COUNT = 5;
		const int BUTTON_SIZE = 30;

		PictureBox[] button;
		int selectedID;

		static FormTool() {
			toolDictionary = new Dictionary<string, IDrawTool>();
		}

		public FormTool(DockPanel dockPanel, ToolStripMenuItem item) : base(dockPanel, item) {
			InitializeComponent();

			GenerateButton();

			selectedTool = GetToolFromID(0);
			DrawToolIcon(SELECTED_COLOR, button[0], GetToolFromID(0).Icon);

		}

		/// <summary>
		/// ボタンを生成する
		/// </summary>
		void GenerateButton() {

			button = new PictureBox[BUTTON_COUNT];
			for(int i = 0;i < BUTTON_COUNT;i++) {

				//ボタンの初期設定
				button[i] = new PictureBox();

				button[i].Location = new Point(
					BUTTON_STARTPOSITION.X,
					BUTTON_STARTPOSITION.Y + (BUTTON_STARTPOSITION.Y + BUTTON_SIZE) * i);
				button[i].Size = new Size(BUTTON_SIZE, BUTTON_SIZE);

				DrawToolIcon(BACKGROUND_COLOR, button[i], GetToolFromID(i).Icon);

				var temp = i;
				button[i].Click += (object sender, EventArgs e) => {
					DrawToolIcon(BACKGROUND_COLOR, button[selectedID], GetToolFromID(selectedID).Icon);

					var tool = GetToolFromID(temp);
					DrawToolIcon(SELECTED_COLOR, button[temp], tool.Icon);
					selectedTool = tool;
					selectedID = temp;
				};

				//コントロールに追加
				FlowLayout.Controls.Add(button[i]);

			}

		}

		/// <summary>
		/// ツールのアイコンを描画
		/// </summary>
		/// <param name="BaseColor"></param>
		/// <param name="pictureBox"></param>
		/// <param name="icon"></param>
		void DrawToolIcon(Color BaseColor, PictureBox pictureBox, Image icon) {

			var canvas = new Bitmap(pictureBox.Size.Width, pictureBox.Size.Height);
			var g = Graphics.FromImage(canvas);

			Rectangle rect = new Rectangle(new Point(), canvas.Size);

			var brush = new SolidBrush(BaseColor);
			g.FillRectangle(brush, rect);
			brush.Dispose();

			g.DrawImage(icon, rect);


			pictureBox.Image = canvas;

			g.Dispose();

		}

		/// <summary>
		/// IDから対象のツールを返す
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
		IDrawTool GetToolFromID(int id) {
			switch(id) {
				case 0: return GetTool<DrawToolPen>();
				case 1: return GetTool<DrawToolPen>();
				case 2: return GetTool<DrawToolPen>();
				case 3: return GetTool<DrawToolPen>();
				case 4: return GetTool<DrawToolPen>();
				default: return null;
			}
		}

		/// <summary>
		/// 指定したクラスの本体を返す
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns></returns>
		public static IDrawTool GetTool<T>() where T : IDrawTool, new() {

			var key = typeof(T).ToString();

			if(!toolDictionary.ContainsKey(key)) {
				toolDictionary.Add(key, new T());
			}

			return toolDictionary[key];
		}
	}
}

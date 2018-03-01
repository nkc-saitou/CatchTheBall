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
	/// コンテンツの拡大率を設定できるウィンドウ
	/// </summary>
	public partial class FormResizableWindow : FormWindowBase {

		const float DEFAULT_SIZE = 1;
		const float MAX_SIZE = 4;
		const float MIN_SIZE = 0.25f;
		const float CHANGE_SIZE_DELTA = 0.1f;

		public float CurrentSize { get; protected set; }

		protected FormResizableWindow() {
			InitializeComponent();
		}
		public FormResizableWindow(DockPanel dockPanel, ToolStripMenuItem item) : base(dockPanel, item) {
			InitializeComponent();

			CurrentSize = 1;

			//マウスホイールを動かした時
			MouseWheel += OnMouseWheel;

			//ビューのサイズが変更されたら自分も変更する
			SystemData.Instance.ViewMagnificationChanged += ChangeSize;
		}

		~FormResizableWindow() {

			//イベントの削除
			SystemData.Instance.ViewMagnificationChanged -= ChangeSize;
		}

		protected void OnMouseWheel(object sender, MouseEventArgs e) {
			if((ModifierKeys & Keys.Alt) == Keys.Alt) {
				ChangeSize(CurrentSize + e.Delta / Math.Abs(e.Delta) * CHANGE_SIZE_DELTA);
			}
		}

		/// <summary>
		/// サイズを変更する
		/// </summary>
		/// <param name="newSize"></param>
		protected void ChangeSize(float newSize) {

			newSize = Math.Max(newSize, MIN_SIZE);
			newSize = Math.Min(newSize, MAX_SIZE);

			StatusButton.Text = (newSize * 100).ToString("##") + "%";
			CurrentSize = newSize;

			SystemData.Instance.ViewMagnification = newSize;
		}

		private void StatusButton_DropDownItemClicked(object sender, ToolStripItemClickedEventArgs e) {
			ChangeSize(float.Parse((string)e.ClickedItem.Tag));
		}

	}
}

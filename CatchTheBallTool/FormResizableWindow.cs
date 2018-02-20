using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CatchTheBallTool {
	public partial class FormResizableWindow : FormWindowBase {

		const float DEFAULT_SIZE = 1;
		const float MAX_SIZE = 4;
		const float MIN_SIZE = 0.25f;
		const float CHANGE_SIZE_DELTA = 0.1f;

		public float CurrentSize { get; protected set; }

		protected FormResizableWindow() {
			InitializeComponent();
		}
		public FormResizableWindow(ToolStripMenuItem item) : base(item) {
			InitializeComponent();

			CurrentSize = 1;

			MouseWheel += (object sender, MouseEventArgs e) => {
				if((ModifierKeys & Keys.Control) == Keys.Control) {
					ChanceSize(CurrentSize + e.Delta / Math.Abs(e.Delta) * CHANGE_SIZE_DELTA);
				}
			};
		}

		private void StatusButton_DropDownItemClicked(object sender, ToolStripItemClickedEventArgs e) {
			ChanceSize(float.Parse((string)e.ClickedItem.Tag));
		}

		void ChanceSize(float newSize) {

			newSize = Math.Max(newSize, MIN_SIZE);
			newSize = Math.Min(newSize, MAX_SIZE);

			StatusButton.Text = (newSize * 100).ToString("##") + "%";
			CurrentSize = newSize;
			OnSizeChanged();
		}


		protected virtual void OnSizeChanged() { }
	}
}

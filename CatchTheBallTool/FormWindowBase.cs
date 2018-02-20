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
	public partial class FormWindowBase : WeifenLuo.WinFormsUI.Docking.DockContent {

		private FormWindowBase() {
			InitializeComponent();

		}

		public FormWindowBase(ToolStripMenuItem item) {

			Shown += (_, __) => {
				item.Checked = true;
			};

			FormClosing += (object sender, FormClosingEventArgs e) => {

				//親が閉じられる場合はそのまま閉じる
				if(e.CloseReason == CloseReason.MdiFormClosing) return;

				e.Cancel = true;
				item.Checked = false;
				Hide();
			};
		}
	}
}

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
	/// ステージを編集するウィンドウ
	/// </summary>
	public partial class FormView : FormResizableWindow {

		public FormView(DockPanel dockPanel, ToolStripMenuItem item) : base(dockPanel, item) {
			InitializeComponent();

		}

		private void FormView_Load(object sender, EventArgs e) {

		}
	}
}

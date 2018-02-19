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
	public partial class FormView : WeifenLuo.WinFormsUI.Docking.DockContent {
		public FormView() {
			InitializeComponent();
		}

		private void FormView_Load(object sender, EventArgs e) {

		}

		protected override string GetPersistString() {
			return "FormView";
		}
	}
}

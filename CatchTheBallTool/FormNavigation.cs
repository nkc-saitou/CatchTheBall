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
	public partial class FormNavigation : WeifenLuo.WinFormsUI.Docking.DockContent {
		public FormNavigation() {
			InitializeComponent();
		}

		protected override string GetPersistString() {
			return "FormNavigation";
		}
	}
}

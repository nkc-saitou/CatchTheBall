using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace CatchTheBallTool {
	public partial class FormMapChip : WeifenLuo.WinFormsUI.Docking.DockContent {
		public FormMapChip() {
			InitializeComponent();
		}

		protected override string GetPersistString() {
			return "FormMapChip";
		}
	}
}

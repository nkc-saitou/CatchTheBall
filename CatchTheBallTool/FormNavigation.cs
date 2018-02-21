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

	/// <summary>
	/// 全体を表示するウィンドウ
	/// </summary>
	public partial class FormNavigation : FormResizableWindow {

		public FormNavigation(ToolStripMenuItem item) : base(item) {
			InitializeComponent();

		}
	}
}

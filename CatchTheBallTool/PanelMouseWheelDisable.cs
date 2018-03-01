using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CatchTheBallTool {


	class PanelMouseWheelDisable : Panel {

		const int WM_MOUSEWHEEL = 0x020A;

		public bool IsDisableWheel { get; set; } = true;

		protected override void WndProc(ref Message m) {
			if(IsDisableWheel && m.HWnd == Handle && m.Msg == WM_MOUSEWHEEL) return;

			base.WndProc(ref m);
		}

	}
}

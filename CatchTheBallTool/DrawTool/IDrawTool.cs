using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows.Forms;

namespace CatchTheBallTool {
	public interface IDrawTool {

		void MouseDown(FormView formView, Point mousePosition, MouseButtons button);
		void MouseMove(FormView formView, Point mousePosition, MouseButtons button);
		void MouseUp(FormView formView, Point mousePosition, MouseButtons button);

	}
}

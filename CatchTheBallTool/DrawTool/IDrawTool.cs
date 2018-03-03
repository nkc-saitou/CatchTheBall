using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows.Forms;

namespace CatchTheBallTool {

	/// <summary>
	/// 描画用ツールの機能を実装するインターフェース
	/// </summary>
	public interface IDrawTool {

		Image Icon { get; set; }

		void MouseDown(FormView formView, Point mousePosition, MouseButtons button);
		void MouseMove(FormView formView, Point mousePosition, MouseButtons button);
		void MouseUp(FormView formView, Point mousePosition, MouseButtons button);

	}
}

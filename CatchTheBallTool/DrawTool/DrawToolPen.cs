using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using CatchTheBallTool.Commnad;

namespace CatchTheBallTool.DrawTool {

	public class DrawToolPen : IDrawTool {

		List<Point> position;
		List<int> prevMapChip;
		MouseButtons state = MouseButtons.None;

		int chip = 0;

		public void MouseDown(FormView formView, Point mousePosition, MouseButtons button) {
			position = new List<Point>();
			prevMapChip = new List<int>();
			if(state != MouseButtons.None) return;

			state = button;
			chip = GetChip(button);
			SetMapChip(formView, mousePosition);
		}

		public void MouseMove(FormView formView, Point mousePosition, MouseButtons button) {

			if(button == MouseButtons.None || button != state) return;
			SetMapChip(formView, mousePosition);
		}

		public void MouseUp(FormView formView, Point mousePosition, MouseButtons button) {
			if(state != button) return;

			state = MouseButtons.None;

			var command = new CommandSetMapChip(position.ToArray(), chip);
			command.prevMapChip = prevMapChip.ToArray();

			CommandStream.Instance.AddStream(command);
		}

		int GetChip(MouseButtons button) {
			return state == MouseButtons.Left ? SystemData.Instance.SelectMapChip : -1;
		}

		/// <summary>
		/// 指定した位置にマップチップを置く
		/// </summary>
		void SetMapChip(FormView formView, Point mousePosition) {

			var stagePosition = formView.CalcMapPosition(mousePosition);

			if(position.Any(item => item == stagePosition)) return;

			prevMapChip.Add(StageData.Instance.Map[stagePosition.Y][stagePosition.X]);
			position.Add(stagePosition);

			StageData.Instance.SetStageData(stagePosition, chip);

			formView.Draw();
		}
	}
}

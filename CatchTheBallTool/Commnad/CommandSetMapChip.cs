using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace CatchTheBallTool.Commnad {

	/// <summary>
	/// マップチップを配置するコマンド
	/// </summary>
	public class CommandSetMapChip : ICommand {

		Point position;
		int mapChip;
		int prevMapChip;

		public CommandSetMapChip(Point position, int mapChip) {
			this.position = position;
			this.mapChip = mapChip;
		}

		public void Execute() {

			var map = StageData.Instance.Map;
			prevMapChip = map[position.Y][position.X];
			map[position.Y][position.X] = mapChip;

			FormView.DrawView();

			//編集フラグを変更
			SystemData.Instance.IsEdit = true;
		}

		public void Undo() {

			StageData.Instance.Map[position.Y][position.X] = prevMapChip;

			FormView.DrawView();

			//編集フラグを変更
			SystemData.Instance.IsEdit = true;

		}
	}
}

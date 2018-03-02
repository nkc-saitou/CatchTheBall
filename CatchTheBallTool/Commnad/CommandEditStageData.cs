using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace CatchTheBallTool.Commnad {

	/// <summary>
	/// ステージデータの編集を行うコマンド
	/// </summary>
	class CommandEditStageData : ICommand {

		Size newMapSize;
		Size prevMapSize;

		public CommandEditStageData(Size newMapSize) {
			this.newMapSize = newMapSize;
		}

		public void Execute() {

			//マップサイズ変更
			prevMapSize = StageData.Instance.MapSize;
			StageData.Instance.ResizeMap(newMapSize);
			FormMain.Instance.GetWindow<FormView>().Draw();

			//編集フラグを変更
			SystemData.Instance.IsEdit = true;
		}

		public void Undo() {

			//マップサイズ変更
			StageData.Instance.ResizeMap(prevMapSize);
			FormMain.Instance.GetWindow<FormView>().Draw();

			//編集フラグを戻さない
			SystemData.Instance.IsEdit = true;
		}
	}
}

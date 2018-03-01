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

		string newMapChipPath;
		string prevMapChipPath;

		public CommandEditStageData(Size newMapSize, string newMapChipPath) {
			this.newMapSize = newMapSize;
			this.newMapChipPath = newMapChipPath;
		}

		public void Execute() {

			//マップサイズ変更
			prevMapSize = StageData.Instance.MapSize;
			StageData.Instance.ResizeMap(newMapSize);
			//マップチップ変更
			prevMapChipPath = SystemData.Instance.MapChipPath;
			SystemData.Instance.MapChipPath = newMapChipPath;

			SystemData.Instance.Load();
			FormMain.Instance.GetWindow<FormView>().Draw();

			//編集フラグを変更
			SystemData.Instance.IsEdit = true;
		}

		public void Undo() {

			//マップサイズ変更
			StageData.Instance.ResizeMap(prevMapSize);
			//マップチップ変更
			SystemData.Instance.MapChipPath = prevMapChipPath;

			//更新
			SystemData.Instance.Load();
			FormMain.Instance.GetWindow<FormView>().Draw();

			//編集フラグを戻さない
			SystemData.Instance.IsEdit = true;
		}
	}
}

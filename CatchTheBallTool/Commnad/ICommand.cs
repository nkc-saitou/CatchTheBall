using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CatchTheBallTool {
	public interface ICommand {

		/// <summary>
		/// コマンドを実行
		/// </summary>
		void Execute();

		/// <summary>
		/// コマンドの操作を戻す
		/// </summary>
		void Undo();

	}
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CatchTheBallTool {

	/// <summary>
	/// 実行されたコマンドを管理する
	/// </summary>
	public sealed class CommandStream : Singleton<CommandStream>{

		List<ICommand> stream;
		public int Current { get; private set; }

		public event Action ExecuteCommandEvent;
		public event Action UndoCommandEvent;

		protected override void Initialize() {
			base.Initialize();

			ClearCommand();
		}

		public void ClearCommand() {
			stream = new List<ICommand>();
			Current = -1;
		}

		/// <summary>
		/// コマンドを実行する
		/// </summary>
		/// <param name="command"></param>
		public void ExecuteCommand(ICommand command) {

			command.Execute();
			AddStream(command);

			if(ExecuteCommandEvent != null) ExecuteCommandEvent();
		}

		/// <summary>
		/// ストリームに実行済みコマンドを追加
		/// </summary>
		/// <param name="command"></param>
		public void AddStream(ICommand command) {
			//後のコマンドを削除する
			if(stream.Count > Current + 1) {
				stream.RemoveRange(Current + 1, stream.Count - (Current + 1));
				Current = stream.Count - 1;
			}

			stream.Add(command);
			Current++;

			if(ExecuteCommandEvent != null) ExecuteCommandEvent();
		}

		public void Retry() {
			ExecuteCommand(stream[Current]);
		}

		public void UndoCommand() {
			if(!CanUndo()) return;
			stream[Current--].Undo();

			if(UndoCommandEvent != null) UndoCommandEvent();
		}
		public void RedoCommand() {
			if(!CanRedo()) return;
			stream[++Current].Execute();

			if(ExecuteCommandEvent != null) ExecuteCommandEvent();
		}

		public bool CanUndo() {
			return Current >= 0 && Current < stream.Count;
		}

		public bool CanRedo() {
			return Current < stream.Count - 1 && Current >= -1;
		}
	}
}

﻿using System;
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

		public int[] prevMapChip { get; set; }

		Point[] position;
		int[] mapChip;

		public CommandSetMapChip(Point position, int mapChip) {
			this.position = new Point[] { position };
			this.mapChip = new int[] { mapChip };
		}

		public CommandSetMapChip(Point[] position, int mapChip) {
			this.position = new Point[position.Length];
			position.CopyTo(this.position, 0);
			this.mapChip = Enumerable.Repeat(mapChip, position.Length).ToArray();
		}

		public CommandSetMapChip(Point[] position, int[] mapChip) {
			this.position = new Point[position.Length];
			position.CopyTo(this.position, 0);
			this.mapChip = new int[mapChip.Length];
			mapChip.CopyTo(this.mapChip, 0);
		}

		public void Execute() {

			var map = StageData.Instance.Map;
			prevMapChip = new int[position.Length];
			for(int i = 0;i < position.Length;i++) {
				prevMapChip[i] = map[position[i].Y][position[i].X];
				map[position[i].Y][position[i].X] = mapChip[i];
			}

			FormMain.Instance.GetWindow<FormView>().Draw();

			//編集フラグを変更
			SystemData.Instance.IsEdit = true;
		}

		public void Undo() {

			var map = StageData.Instance.Map;
			for(int i = 0;i < position.Length;i++) {
				map[position[i].Y][position[i].X] = prevMapChip[i];
			}

			FormMain.Instance.GetWindow<FormView>().Draw();

			//編集フラグを変更
			SystemData.Instance.IsEdit = true;

		}
	}
}

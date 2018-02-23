using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace CatchTheBallTool {

	/// <summary>
	/// ステージに登場する物体
	/// </summary>
	public class Object {

		public int id;
		public Point position;

		public Object(int id, Point position) {

			this.id = id;
			this.position = position;
		}

	}
}

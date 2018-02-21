using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CatchTheBallTool {
	public class Singleton<T> where T : class, new(){

		static readonly T instance = new T();
		public static T Instance {
			get { return instance; }
		}

		/// <summary>
		/// 外部からのnewを禁止する
		/// </summary>
		private Singleton() {
			Initialize();
		}

		/// <summary>
		/// 初期化するときに呼ばれる
		/// </summary>
		protected virtual void Initialize() {
		}

	}
}

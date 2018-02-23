using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CatchTheBallTool {
	public class Singleton<T> where T : class, new() {

		static volatile T instance = new T();
		static object syncbject = new object();

		public static T Instance {
			get {
				if(instance == null) {
					//ロックをかけて生成する
					lock(syncbject) if(instance == null) return instance = new T();
				}
				return instance;
			}
		}

		/// <summary>
		/// 外部からのnewを禁止する
		/// </summary>
		protected Singleton() {
			Initialize();
		}

		/// <summary>
		/// 初期化するときに呼ばれる
		/// </summary>
		protected virtual void Initialize() { }

	}
}

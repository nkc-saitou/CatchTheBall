using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CatchTheBallTool {

	/// <summary>
	/// 便利メソッドまとめ
	/// </summary>
	public static class Utility {

		/// <summary>
		/// 番号かどうかを調べる(バックスペースも許す)
		/// </summary>
		/// <param name="c"></param>
		/// <returns></returns>
		public static bool IsNumber(this char c) {
			return c >= '0' && '9' >= c || c == '\b';
		}

		/// <summary>
		/// ファイルパス(拡張子付き)からファイル名を抜き出す
		/// </summary>
		/// <param name="s">ファイルパス(拡張子付き)</param>
		/// <returns>ファイル名</returns>
		public static string GetFileName(this string s) {

			var buff = s.Split('/', '.');
			return buff[buff.Length - 2];
		}

	}
}

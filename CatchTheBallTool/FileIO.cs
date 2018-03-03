using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CatchTheBallTool {

	/// <summary>
	/// ファイルの入出力を扱うクラス
	/// </summary>
	public static class FileIO {

		/// <summary>
		/// 指定の場所にファイルを保存する
		/// </summary>
		/// <param name="path"></param>
		/// <returns></returns>
		public static bool SaveFile(string path, string data) {

			using(StreamWriter sw = new StreamWriter(
				path, false, Encoding.GetEncoding("UTF-8"))) {
				sw.Write(data);
			}

			return true;
		}

		public static string LoadFile(string path) {

			string text = "";

			using(StreamReader sr = new StreamReader(
				path, Encoding.GetEncoding("UTF-8"))) {
				text = sr.ReadToEnd();
			}

			return text;

		}

	}
}

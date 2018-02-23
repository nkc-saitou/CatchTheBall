using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace CatchTheBallTool {

	/// <summary>
	/// ステージデータの各パラメータ
	/// </summary>
	public sealed class StageData : Singleton<StageData> {

		public const string STAGE_DATA_EXT = "ctbst";

		readonly Size DEFAULT_MAPSIZE = new Size(1, 1);

		public string StageName { get; set; }			//ファイル名
		public string StagePath { get; set; }			//拡張子付き
		public Size MapSize { get; set; }
		public List<List<int>> Map { get; set; }
		public List<Object> ObjectList { get; set; }

		public StageData() { }

		protected override void Initialize() {
			base.Initialize();

			StagePath = "";
			StageName = "";

			MapSize = DEFAULT_MAPSIZE;
			Map = new List<List<int>>();
			ObjectList = new List<Object>();

			MapSize = DEFAULT_MAPSIZE;
		}

		public void Load() {

			for(int i = 0;i < MapSize.Height;i++) {

				var column = new List<int>();
				for(int j = 0;j < MapSize.Width;j++) {
					column.Add(-1);
				}

				Map.Add(column);
			}
		}

		/// <summary>
		/// マップをリサイズする
		/// </summary>
		/// <param name="newSize"></param>
		public void ResizeMap(Size newSize) {

			//横方向のサイズ変更
			if(newSize.Width > MapSize.Width) {

				var diff = newSize.Width - MapSize.Width;
				for(int i = 0;i < Map.Count;i++) {
					for(int j = 0;j < diff;j++) {
						Map[i].Add(-1);
					}
				}
			}

			//縦方向のサイズ変更
			if(newSize.Height > MapSize.Height) {

				var diff = newSize.Height - MapSize.Height;
				for(int i = 0;i < diff;i++) {

					var column = new List<int>();
					for(int j = 0;j < newSize.Width;j++) {
						column.Add(-1);
					}

					Map.Add(column);
				}
			}

			MapSize = newSize;
		}

		#region IO

		public bool Import(string data) {

			var count = 0;				//文字のカウンター
			Size mapSize;
			var map = new List<List<int>>();
			var objectList = new List<Object>();

			//改行を抜く
			data = new string(data
				.Where(item => item != '\n')
				.ToArray());

			var dataSet = data.Split(',');

			try {
				//マップサイズを読み込む
				mapSize = new Size(int.Parse(dataSet[count++]), int.Parse(dataSet[count++]));

				//マップを読み込む
				for(int i = 0;i < mapSize.Height;i++) {

					var column = new List<int>();
					for(int j = 0;j < mapSize.Width;j++) {
						column.Add(int.Parse(dataSet[count++]));
					}
					map.Add(column);
				}

				//オブジェクトの数を読み込む
				var objectCount = int.Parse(dataSet[count++]);

				//オブジェクトを読み込む
				for(int i = 0;i < objectCount;i++) {
					objectList.Add(new Object(
						int.Parse(dataSet[count++]),
						new Point(int.Parse(dataSet[count++]), int.Parse(dataSet[count++]))));
				}
			}
			catch { return false; }

			//反映する
			MapSize = mapSize;
			Map = map;
			ObjectList = objectList;

			return true;
		}

		/// <summary>
		/// ステージデータのファイル用文字列を取得する
		/// </summary>
		/// <returns></returns>
		public string Export() {

			StringBuilder sb = new StringBuilder();

			//ステージのサイズを格納
			sb.Append(MapSize.Width);
			sb.Append(",");
			sb.Append(MapSize.Height);
			sb.Append(",\n");

			//ステージデータを格納
			for(int i = 0;i < MapSize.Height;i++) {
				for(int j = 0;j < MapSize.Width;j++) {
					sb.Append(Map[i][j]);
					sb.Append(",");
				}
				sb.Append("\n");
			}

			//オブジェクトの数を格納
			sb.Append(ObjectList.Count);
			sb.Append(",\n");

			//オブジェクトを格納
			for(int i = 0;i < ObjectList.Count;i++) {
				sb.Append(ObjectList[i].id);
				sb.Append(",");
				sb.Append(ObjectList[i].position.X);
				sb.Append(",");
				sb.Append(ObjectList[i].position.Y);
				sb.Append(",\n");
			}

			return sb.ToString();
		}

		#endregion
	}
}

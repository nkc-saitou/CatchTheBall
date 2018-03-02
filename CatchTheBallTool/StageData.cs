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
		public const string DEFAULT_STAGE_NAME = "NewStage";

		readonly Size DEFAULT_MAPSIZE = new Size(10, 5);

		public string StageName { get; set; }			//ファイル名
		public string StagePath { get; set; }			//拡張子付き
		public Size MapSize { get; private set; }
		public List<List<int>> StageMap { get; private set; }
		public List<List<int>> ObjectMap { get; private set; }

		public event Action MapSizeChanged;

		public StageData() { }

		protected override void Initialize() {
			base.Initialize();

			StageName = DEFAULT_STAGE_NAME;
			StagePath = "";

			MapSize = DEFAULT_MAPSIZE;

			LoadMap();
		}

		public void LoadMap() {

			StageMap = new List<List<int>>();
			ObjectMap = new List<List<int>>();

			for(int i = 0;i < MapSize.Height;i++) {

				var stageColumn = new List<int>();
				var objectColumn = new List<int>();
				for(int j = 0;j < MapSize.Width;j++) {
					stageColumn.Add(-1);
					objectColumn.Add(-1);
				}

				StageMap.Add(stageColumn);
				ObjectMap.Add(objectColumn);
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
				for(int i = 0;i < StageMap.Count;i++) {
					for(int j = 0;j < diff;j++) {
						StageMap[i].Add(-1);
						ObjectMap[i].Add(-1);
					}
				}
			}

			//縦方向のサイズ変更
			if(newSize.Height > MapSize.Height) {

				var diff = newSize.Height - MapSize.Height;
				for(int i = 0;i < diff;i++) {

					var stageColumn = new List<int>();
					var objectColumn = new List<int>();
					for(int j = 0;j < newSize.Width;j++) {
						stageColumn.Add(-1);
						objectColumn.Add(-1);
					}

					StageMap.Add(objectColumn);
					ObjectMap.Add(stageColumn);
				}
			}

			MapSize = newSize;

			//マップサイズ変更イベント発火
			if(MapSizeChanged != null) MapSizeChanged();
		}

		/// <summary>
		/// 指定した位置にマップチップを配置する
		/// </summary>
		/// <param name="position"></param>
		/// <param name="mapchipNum"></param>
		/// <returns></returns>
		public bool SetStageData(Point position, int mapchipNum) {
			if(!CheckInsideMap(position)) return false;

			StageMap[position.Y][position.X] = mapchipNum;

			return true;
		}

		/// <summary>
		/// 指定した位置がマップ内か
		/// </summary>
		/// <returns></returns>
		public bool CheckInsideMap(Point position) {
			if(position.X < 0 || position.X >= MapSize.Width) return false;
			if(position.Y < 0 || position.Y >= MapSize.Height) return false;

			return true;
		}

		#region IO
		/// <summary>
		/// ステージデータを読み込む
		/// </summary>
		/// <param name="data"></param>
		/// <returns></returns>
		public bool Import(string data) {

			var count = 0;				//文字のカウンター
			Size mapSize;
			var stageMap = new List<List<int>>();
			var objectMap = new List<List<int>>();

			//改行を抜く
			data = new string(data
				.Where(item => item != '\n')
				.ToArray());

			var dataSet = data.Split(',');

			try {
				//マップサイズを読み込む
				mapSize = new Size(int.Parse(dataSet[count++]), int.Parse(dataSet[count++]));

				//ステージマップを読み込む
				for(int i = 0;i < mapSize.Height;i++) {

					var column = new List<int>();
					for(int j = 0;j < mapSize.Width;j++) {
						column.Add(int.Parse(dataSet[count++]));
					}
					stageMap.Add(column);
				}

				//オブジェクトマップを読み込む
				for(int i = 0;i < mapSize.Height;i++) {

					var column = new List<int>();
					for(int j = 0;j < mapSize.Width;j++) {
						column.Add(int.Parse(dataSet[count++]));
					}
					objectMap.Add(column);
				}
			}
			catch { return false; }

			//反映する
			MapSize = mapSize;
			StageMap = stageMap;
			ObjectMap = objectMap;

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
					sb.Append(StageMap[i][j]);
					sb.Append(",");
				}
				sb.Append("\n");
			}

			//オブジェクトデータを格納
			for(int i = 0;i < MapSize.Height;i++) {
				for(int j = 0;j < MapSize.Width;j++) {
					sb.Append(ObjectMap[i][j]);
					sb.Append(",");
				}
				sb.Append("\n");
			}
			return sb.ToString();
		}
		#endregion
	}
}

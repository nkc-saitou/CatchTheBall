using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace CatchTheBallTool {

	/// <summary>
	/// 等分された画像を管理するクラス(マップチップ等)
	/// </summary>
	public class ImageAtlas {

		public Bitmap AtlasImage { get; }
		public Bitmap this[int index] {
			get { return GetBitmapFromID(index); }
		}
		public Size ChipSize { get; }
		public Size ChipCount { get; }

		public ImageAtlas(Image image, Size chipSize) {
			AtlasImage = new Bitmap(image);
			ChipSize = chipSize;
			ChipCount = new Size(AtlasImage.Size.Width / ChipSize.Width, AtlasImage.Size.Height / ChipSize.Height);
		}

		public Bitmap GetBitmapFromID(int id) {

			//例外
			if(id < 0 || id >= ChipCount.Width * ChipCount.Height) return null;

			var startPoint = 
				new Point(id % ChipCount.Width * ChipSize.Width, id / ChipCount.Width * ChipSize.Height);

			return AtlasImage.Clone(new Rectangle(startPoint, ChipSize), AtlasImage.PixelFormat);

		}

		~ImageAtlas() {
			AtlasImage.Dispose();
		}
	}
}

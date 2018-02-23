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

		public Bitmap atlasImage { get; }
		public Bitmap this[int index] {
			get { return GetBitmapFromID(index); }
		}
		public Size chipSize { get; }

		public int count { get { return (atlasImage.Size.Width / chipSize.Width) * (atlasImage.Size.Height / chipSize.Height); } }

		public ImageAtlas(Image image, Size chipSize) {
			this.atlasImage = new Bitmap(image);
			this.chipSize = chipSize;
		}

		public Bitmap GetBitmapFromID(int id) {

			//例外
			if(id < 0 || id >= count) return null;

			int xCount = atlasImage.Size.Width / chipSize.Width;
			Point startPoint = new Point(id / xCount, id - xCount * (id / xCount));

			return atlasImage.Clone(new Rectangle(startPoint, chipSize), atlasImage.PixelFormat);

		}

		~ImageAtlas() {
			atlasImage.Dispose();
		}
	}
}

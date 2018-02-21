using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace CatchTheBallTool {

	/// <summary>
	/// マップチップを選択できるウィンドウ
	/// </summary>
	public partial class FormMapChip : FormResizableWindow {

		const string MAPCHIP_PATH = @"";	//マップチップのパス
		const int MAPCHIP_SIZE = 64;		//マップチップのサイズ(px)

		Graphics g;

		public FormMapChip(ToolStripMenuItem item) : base(item) {
			InitializeComponent();

		}

		private void toolStripDropDownButton1_Click(object sender, EventArgs e) {

		}
	}
}

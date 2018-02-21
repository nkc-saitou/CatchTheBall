using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CatchTheBallTool {

	/// <summary>
	/// 子ウィンドウでの共通の処理を記述
	/// </summary>
	public partial class FormWindowBase : WeifenLuo.WinFormsUI.Docking.DockContent {

		protected FormWindowBase() {
			InitializeComponent();
		}

		public FormWindowBase(ToolStripMenuItem item) {

			//可視状態の変更時
			VisibleChanged += (object sender, EventArgs e) => {
				item.Checked = Visible;
			};

			//フォームが閉じられる前
			FormClosing += (object sender, FormClosingEventArgs e) => {

				//親が閉じられる場合はそのまま閉じる
				if(e.CloseReason == CloseReason.MdiFormClosing) return;

				e.Cancel = true;
				Hide();
			};
		}

		protected override string GetPersistString() {
			return Text;
		}
	}
}

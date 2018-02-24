using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WeifenLuo.WinFormsUI.Docking;

namespace CatchTheBallTool {

	/// <summary>
	/// 子ウィンドウでの共通の処理を記述
	/// </summary>
	public abstract partial class FormWindowBase : DockContent {

		DockPanel mainDockPanel;
		ToolStripMenuItem menuItem;

		protected FormWindowBase() {
			InitializeComponent();
		}

		public FormWindowBase(DockPanel dockPanel, ToolStripMenuItem item) {
			InitializeComponent();

			mainDockPanel = dockPanel;
			menuItem = item;

			//フォームが閉じられる前
			FormClosing += (object sender, FormClosingEventArgs e) => {

				//親が閉じられる場合はそのまま閉じる
				if(e.CloseReason == CloseReason.MdiFormClosing) return;

				e.Cancel = true;
				Hide();
			};

			//各イベントの追加
			VisibleChanged += VisibleChangedExec;
			menuItem.Click += ItemClick;

			Disposed += (object sender, EventArgs e) => 
			{
				//各イベントの削除
				VisibleChanged -= VisibleChangedExec;
				menuItem.Click -= ItemClick;
			};
		}

		void ItemClick(object sender, EventArgs e) {
			Show(mainDockPanel);
		}

		void VisibleChangedExec(object sender, EventArgs e) {
			menuItem.Checked = Visible;
		}

		public static string WindowPersistString<T>() where T : FormWindowBase {
			return "CatchTheBallTool." + typeof(T).ToString();
		}
	}
}

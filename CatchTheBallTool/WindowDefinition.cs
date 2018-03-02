using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WeifenLuo.WinFormsUI.Docking;

namespace CatchTheBallTool {

	/// <summary>
	/// ウィンドウ定義のみ
	/// </summary>
	public class WindowDefinition {

		public static Dictionary<string, Func<DockPanel, FormWindowBase>> windowDictionary {
			get; private set;
		}

		/// <summary>
		/// ウィンドウの設定
		/// </summary>
		static WindowDefinition() {
			windowDictionary = new Dictionary<string, Func<DockPanel, FormWindowBase>>();

			windowDictionary.Add(
				typeof(FormView).ToString(),
				(panel) => new FormView(panel, FormMain.Instance.ビューVToolStripMenuItem)
				);

			windowDictionary.Add(
				typeof(FormMapChip).ToString(),
				(panel) => new FormMapChip(panel, FormMain.Instance.マップチップMToolStripMenuItem)
				);

			windowDictionary.Add(
				typeof(FormNavigation).ToString(),
				(panel) => new FormNavigation(panel, FormMain.Instance.ナビゲーションNToolStripMenuItem)
				);

			windowDictionary.Add(
				typeof(FormTool).ToString(),
				(panel) => new FormTool(panel, FormMain.Instance.ツールTToolStripMenuItem)
				);

			windowDictionary.Add(
				typeof(FormObjectData).ToString(),
				(panel) => new FormObjectData(panel, FormMain.Instance.オブジェクトカウンタCToolStripMenuItem)
				);
		}
	}
}

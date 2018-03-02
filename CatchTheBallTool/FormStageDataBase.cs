using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CatchTheBallTool {

	/// <summary>
	/// ステージデータの設定を行うベースフォーム
	/// </summary>
	public partial class FormStageDataBase : Form {
		public FormStageDataBase() {
			InitializeComponent();

			TextBoxMapSizeX.Text = StageData.Instance.MapSize.Width.ToString();
			TextBoxMapSizeY.Text = StageData.Instance.MapSize.Height.ToString();
		}

		/// <summary>
		/// ステージの名前が正しく入力されているか調べる
		/// </summary>
		/// <returns></returns>
		protected bool CheckStageName() {
			if(TextBoxStageName.Text == "") {
				MessageBox.Show("ステージ名を入力して下さい");
				return false;
			}
			return true;
		}

		/// <summary>
		/// マップサイズが正しく入力されているか調べる
		/// </summary>
		/// <returns></returns>
		protected bool CheckMapSize() {

			int size;

			if(!int.TryParse(TextBoxMapSizeX.Text, out size) || size < 1
				|| !int.TryParse(TextBoxMapSizeY.Text, out size) || size < 1) {

				MessageBox.Show("マップサイズは1以上を指定してください");
				return false;
			}
			return true;
		}

		private void TextBoxMapSizeX_KeyPress(object sender, KeyPressEventArgs e) {
			if(!e.KeyChar.IsNumber()) e.Handled = true;
		}

		private void TextBoxMapSizeY_KeyPress(object sender, KeyPressEventArgs e) {
			if(!e.KeyChar.IsNumber()) e.Handled = true;
		}
	}
}

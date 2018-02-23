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
	public partial class FormStageDataEdit : Form {
		public FormStageDataEdit() {
			InitializeComponent();

			TextBoxStageName.Text = "NewStage";
			TextBoxMapSizeX.Text = StageData.Instance.MapSize.Width.ToString();
			TextBoxMapSizeY.Text = StageData.Instance.MapSize.Height.ToString();
			TextBoxMapChipPath.Text = SystemData.Instance.MapChipPath;
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

		/// <summary>
		/// マップチップのパスが正しく入力されているか調べる
		/// </summary>
		/// <returns></returns>
		protected bool CheckMapChipPath() {

			if(!File.Exists(TextBoxMapChipPath.Text)) {
				MessageBox.Show("マップチップの存在が確認できませんでした");
				return false;
			}
			return true;
		}

		private void ButtonMapChipPath_Click(object sender, EventArgs e) {
			if(OpenFileMapChip.ShowDialog() != DialogResult.OK) return;

			TextBoxMapChipPath.Text = OpenFileMapChip.FileName;
		}

		private void TextBoxMapSizeX_KeyPress(object sender, KeyPressEventArgs e) {
			if(!e.KeyChar.IsNumber()) e.Handled = true;
		}

		private void TextBoxMapSizeY_KeyPress(object sender, KeyPressEventArgs e) {
			if(!e.KeyChar.IsNumber()) e.Handled = true;
		}
	}
}

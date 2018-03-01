using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using CatchTheBallTool.Commnad;

namespace CatchTheBallTool {

	/// <summary>
	/// ステージデータの編集用フォーム
	/// </summary>
	public partial class FormStageDataEdit : FormStageDataBase {
		public FormStageDataEdit() {
			InitializeComponent();

			TextBoxStageName.Text = StageData.Instance.StageName;
			TextBoxStageName.Enabled = false;
		}

		private void ButtonEdit_Click(object sender, EventArgs e) {

			//入力されたデータが正しいかどうかチェック
			if(!CheckMapSize()) return;
			if(!CheckMapChipPath()) return;

			//ステージデータ編集コマンドを実行
			var mapSize = (new Size(int.Parse(TextBoxMapSizeX.Text), int.Parse(TextBoxMapSizeY.Text)));
			CommandStream.Instance.ExecuteCommand(new CommandEditStageData(mapSize, TextBoxMapChipPath.Text));

			DialogResult = DialogResult.OK;
		}

		private void ButtonCancel_Click(object sender, EventArgs e) {
			Close();
		}
	}
}

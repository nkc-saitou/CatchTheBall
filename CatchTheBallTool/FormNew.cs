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
	public partial class FormNew : FormStageDataEdit {

		public FormNew() {
			InitializeComponent();

		}

		private void ButtonNew_Click(object sender, EventArgs e) {

			//入力された情報が正しいかチェック
			if(!CheckStageName()) return;
			if(!CheckMapSize()) return;
			if(!CheckMapChipPath()) return;

			//設定を入力して新規作成
			StageData.Instance.StageName = TextBoxStageName.Text;
			var mapSize = new Size(int.Parse(TextBoxMapSizeX.Text), int.Parse(TextBoxMapSizeY.Text));
			StageData.Instance.MapSize = mapSize;
			StageData.Instance.Load();

			SystemData.Instance.MapChipPath = TextBoxMapChipPath.Text;
			SystemData.Instance.IsEdit = false;
			SystemData.Instance.Load();

			FormMain.Instance.Text = TextBoxStageName.Text;

			//閉じる
			DialogResult = DialogResult.OK;
		}
	}
}

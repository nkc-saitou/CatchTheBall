namespace CatchTheBallTool {
	partial class FormStageDataBase {
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing) {
			if(disposing && (components != null)) {
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent() {
			this.panel1 = new System.Windows.Forms.Panel();
			this.ButtonMapChipPath = new System.Windows.Forms.Button();
			this.TextBoxStageName = new System.Windows.Forms.TextBox();
			this.LabelStageName = new System.Windows.Forms.Label();
			this.TextBoxMapChipPath = new System.Windows.Forms.TextBox();
			this.LabelMapChipPath = new System.Windows.Forms.Label();
			this.LabelMapSize = new System.Windows.Forms.Label();
			this.TextBoxMapSizeY = new System.Windows.Forms.TextBox();
			this.TextBoxMapSizeX = new System.Windows.Forms.TextBox();
			this.LabelMapSizeY = new System.Windows.Forms.Label();
			this.LabelMapSizeX = new System.Windows.Forms.Label();
			this.OpenFileMapChip = new System.Windows.Forms.OpenFileDialog();
			this.panel1.SuspendLayout();
			this.SuspendLayout();
			// 
			// panel1
			// 
			this.panel1.Controls.Add(this.ButtonMapChipPath);
			this.panel1.Controls.Add(this.TextBoxStageName);
			this.panel1.Controls.Add(this.LabelStageName);
			this.panel1.Controls.Add(this.TextBoxMapChipPath);
			this.panel1.Controls.Add(this.LabelMapChipPath);
			this.panel1.Controls.Add(this.LabelMapSize);
			this.panel1.Controls.Add(this.TextBoxMapSizeY);
			this.panel1.Controls.Add(this.TextBoxMapSizeX);
			this.panel1.Controls.Add(this.LabelMapSizeY);
			this.panel1.Controls.Add(this.LabelMapSizeX);
			this.panel1.Location = new System.Drawing.Point(12, 12);
			this.panel1.Name = "panel1";
			this.panel1.Size = new System.Drawing.Size(313, 235);
			this.panel1.TabIndex = 0;
			// 
			// ButtonMapChipPath
			// 
			this.ButtonMapChipPath.Location = new System.Drawing.Point(269, 189);
			this.ButtonMapChipPath.Name = "ButtonMapChipPath";
			this.ButtonMapChipPath.Size = new System.Drawing.Size(19, 19);
			this.ButtonMapChipPath.TabIndex = 4;
			this.ButtonMapChipPath.Text = "...";
			this.ButtonMapChipPath.UseVisualStyleBackColor = true;
			this.ButtonMapChipPath.Click += new System.EventHandler(this.ButtonMapChipPath_Click);
			// 
			// TextBoxStageName
			// 
			this.TextBoxStageName.Font = new System.Drawing.Font("MS UI Gothic", 12F);
			this.TextBoxStageName.ImeMode = System.Windows.Forms.ImeMode.Disable;
			this.TextBoxStageName.Location = new System.Drawing.Point(36, 37);
			this.TextBoxStageName.Name = "TextBoxStageName";
			this.TextBoxStageName.Size = new System.Drawing.Size(100, 23);
			this.TextBoxStageName.TabIndex = 0;
			// 
			// LabelStageName
			// 
			this.LabelStageName.AutoSize = true;
			this.LabelStageName.Font = new System.Drawing.Font("MS UI Gothic", 14F);
			this.LabelStageName.Location = new System.Drawing.Point(14, 15);
			this.LabelStageName.Name = "LabelStageName";
			this.LabelStageName.Size = new System.Drawing.Size(90, 19);
			this.LabelStageName.TabIndex = 0;
			this.LabelStageName.Text = "ステージ名";
			this.LabelStageName.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// TextBoxMapChipPath
			// 
			this.TextBoxMapChipPath.Font = new System.Drawing.Font("MS UI Gothic", 9F);
			this.TextBoxMapChipPath.Location = new System.Drawing.Point(36, 189);
			this.TextBoxMapChipPath.Name = "TextBoxMapChipPath";
			this.TextBoxMapChipPath.Size = new System.Drawing.Size(227, 19);
			this.TextBoxMapChipPath.TabIndex = 3;
			// 
			// LabelMapChipPath
			// 
			this.LabelMapChipPath.AutoSize = true;
			this.LabelMapChipPath.Font = new System.Drawing.Font("MS UI Gothic", 14F);
			this.LabelMapChipPath.Location = new System.Drawing.Point(14, 167);
			this.LabelMapChipPath.Name = "LabelMapChipPath";
			this.LabelMapChipPath.Size = new System.Drawing.Size(135, 19);
			this.LabelMapChipPath.TabIndex = 0;
			this.LabelMapChipPath.Text = "マップチップのパス";
			this.LabelMapChipPath.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// LabelMapSize
			// 
			this.LabelMapSize.AutoSize = true;
			this.LabelMapSize.Font = new System.Drawing.Font("MS UI Gothic", 14F);
			this.LabelMapSize.Location = new System.Drawing.Point(14, 75);
			this.LabelMapSize.Name = "LabelMapSize";
			this.LabelMapSize.Size = new System.Drawing.Size(94, 19);
			this.LabelMapSize.TabIndex = 0;
			this.LabelMapSize.Text = "マップサイズ";
			this.LabelMapSize.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			// 
			// TextBoxMapSizeY
			// 
			this.TextBoxMapSizeY.Font = new System.Drawing.Font("MS UI Gothic", 12F);
			this.TextBoxMapSizeY.ImeMode = System.Windows.Forms.ImeMode.Disable;
			this.TextBoxMapSizeY.Location = new System.Drawing.Point(55, 122);
			this.TextBoxMapSizeY.Name = "TextBoxMapSizeY";
			this.TextBoxMapSizeY.Size = new System.Drawing.Size(100, 23);
			this.TextBoxMapSizeY.TabIndex = 2;
			this.TextBoxMapSizeY.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.TextBoxMapSizeY_KeyPress);
			// 
			// TextBoxMapSizeX
			// 
			this.TextBoxMapSizeX.Font = new System.Drawing.Font("MS UI Gothic", 12F);
			this.TextBoxMapSizeX.ImeMode = System.Windows.Forms.ImeMode.Disable;
			this.TextBoxMapSizeX.Location = new System.Drawing.Point(55, 97);
			this.TextBoxMapSizeX.Name = "TextBoxMapSizeX";
			this.TextBoxMapSizeX.Size = new System.Drawing.Size(100, 23);
			this.TextBoxMapSizeX.TabIndex = 1;
			this.TextBoxMapSizeX.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.TextBoxMapSizeX_KeyPress);
			// 
			// LabelMapSizeY
			// 
			this.LabelMapSizeY.AutoSize = true;
			this.LabelMapSizeY.Font = new System.Drawing.Font("MS UI Gothic", 12F);
			this.LabelMapSizeY.Location = new System.Drawing.Point(33, 125);
			this.LabelMapSizeY.Name = "LabelMapSizeY";
			this.LabelMapSizeY.Size = new System.Drawing.Size(16, 16);
			this.LabelMapSizeY.TabIndex = 1;
			this.LabelMapSizeY.Text = "y";
			this.LabelMapSizeY.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
			// 
			// LabelMapSizeX
			// 
			this.LabelMapSizeX.AutoSize = true;
			this.LabelMapSizeX.Font = new System.Drawing.Font("MS UI Gothic", 12F);
			this.LabelMapSizeX.Location = new System.Drawing.Point(33, 100);
			this.LabelMapSizeX.Name = "LabelMapSizeX";
			this.LabelMapSizeX.Size = new System.Drawing.Size(15, 16);
			this.LabelMapSizeX.TabIndex = 0;
			this.LabelMapSizeX.Text = "x";
			this.LabelMapSizeX.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
			// 
			// OpenFileMapChip
			// 
			this.OpenFileMapChip.DefaultExt = "png";
			this.OpenFileMapChip.FileName = "MapChp";
			this.OpenFileMapChip.Filter = "pngファイル|*.png|すべてのファイル|*.*";
			this.OpenFileMapChip.Title = "マップチップの選択";
			// 
			// FormStageDataBase
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(451, 394);
			this.Controls.Add(this.panel1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.MaximizeBox = false;
			this.MinimizeBox = false;
			this.Name = "FormStageDataBase";
			this.Text = "FormStageDataEdit";
			this.panel1.ResumeLayout(false);
			this.panel1.PerformLayout();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Panel panel1;
		private System.Windows.Forms.Label LabelStageName;
		private System.Windows.Forms.Label LabelMapChipPath;
		private System.Windows.Forms.Label LabelMapSize;
		private System.Windows.Forms.Label LabelMapSizeY;
		private System.Windows.Forms.Label LabelMapSizeX;
		private System.Windows.Forms.Button ButtonMapChipPath;
		private System.Windows.Forms.OpenFileDialog OpenFileMapChip;
		protected System.Windows.Forms.TextBox TextBoxStageName;
		protected System.Windows.Forms.TextBox TextBoxMapChipPath;
		protected System.Windows.Forms.TextBox TextBoxMapSizeY;
		protected System.Windows.Forms.TextBox TextBoxMapSizeX;
	}
}
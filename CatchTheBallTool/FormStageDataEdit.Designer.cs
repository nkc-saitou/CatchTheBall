namespace CatchTheBallTool {
	partial class FormStageDataEdit {
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
			this.ButtonCancel = new System.Windows.Forms.Button();
			this.ButtonEdit = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// ButtonCancel
			// 
			this.ButtonCancel.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
			this.ButtonCancel.Font = new System.Drawing.Font("MS UI Gothic", 16F);
			this.ButtonCancel.Location = new System.Drawing.Point(176, 179);
			this.ButtonCancel.Name = "ButtonCancel";
			this.ButtonCancel.Size = new System.Drawing.Size(149, 41);
			this.ButtonCancel.TabIndex = 4;
			this.ButtonCancel.Text = "キャンセル";
			this.ButtonCancel.UseVisualStyleBackColor = true;
			this.ButtonCancel.Click += new System.EventHandler(this.ButtonCancel_Click);
			// 
			// ButtonEdit
			// 
			this.ButtonEdit.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
			this.ButtonEdit.Font = new System.Drawing.Font("MS UI Gothic", 16F);
			this.ButtonEdit.Location = new System.Drawing.Point(12, 179);
			this.ButtonEdit.Name = "ButtonEdit";
			this.ButtonEdit.Size = new System.Drawing.Size(149, 41);
			this.ButtonEdit.TabIndex = 3;
			this.ButtonEdit.Text = "変更";
			this.ButtonEdit.UseVisualStyleBackColor = true;
			this.ButtonEdit.Click += new System.EventHandler(this.ButtonEdit_Click);
			// 
			// FormStageDataEdit
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(334, 232);
			this.Controls.Add(this.ButtonCancel);
			this.Controls.Add(this.ButtonEdit);
			this.Name = "FormStageDataEdit";
			this.Text = "ステージ編集";
			this.Controls.SetChildIndex(this.ButtonEdit, 0);
			this.Controls.SetChildIndex(this.ButtonCancel, 0);
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Button ButtonCancel;
		private System.Windows.Forms.Button ButtonEdit;
	}
}
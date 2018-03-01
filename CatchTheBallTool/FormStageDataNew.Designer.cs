namespace CatchTheBallTool {
	partial class FormStageDataNew {
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
			this.ButtonNew = new System.Windows.Forms.Button();
			this.ButtonCancel = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// ButtonNew
			// 
			this.ButtonNew.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
			this.ButtonNew.Font = new System.Drawing.Font("MS UI Gothic", 16F);
			this.ButtonNew.Location = new System.Drawing.Point(12, 253);
			this.ButtonNew.Name = "ButtonNew";
			this.ButtonNew.Size = new System.Drawing.Size(149, 41);
			this.ButtonNew.TabIndex = 1;
			this.ButtonNew.Text = "作成";
			this.ButtonNew.UseVisualStyleBackColor = true;
			this.ButtonNew.Click += new System.EventHandler(this.ButtonNew_Click);
			// 
			// ButtonCancel
			// 
			this.ButtonCancel.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
			this.ButtonCancel.Font = new System.Drawing.Font("MS UI Gothic", 16F);
			this.ButtonCancel.Location = new System.Drawing.Point(176, 253);
			this.ButtonCancel.Name = "ButtonCancel";
			this.ButtonCancel.Size = new System.Drawing.Size(149, 41);
			this.ButtonCancel.TabIndex = 2;
			this.ButtonCancel.Text = "キャンセル";
			this.ButtonCancel.UseVisualStyleBackColor = true;
			this.ButtonCancel.Click += new System.EventHandler(this.ButtonCancel_Click);
			// 
			// FormStageDataNew
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(334, 306);
			this.Controls.Add(this.ButtonCancel);
			this.Controls.Add(this.ButtonNew);
			this.Name = "FormStageDataNew";
			this.Text = "新規作成";
			this.Controls.SetChildIndex(this.ButtonNew, 0);
			this.Controls.SetChildIndex(this.ButtonCancel, 0);
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Button ButtonNew;
		private System.Windows.Forms.Button ButtonCancel;
	}
}
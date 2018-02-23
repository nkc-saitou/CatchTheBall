namespace CatchTheBallTool {
	partial class FormNew {
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
			this.SuspendLayout();
			// 
			// ButtonNew
			// 
			this.ButtonNew.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
			this.ButtonNew.Font = new System.Drawing.Font("MS UI Gothic", 16F);
			this.ButtonNew.Location = new System.Drawing.Point(92, 253);
			this.ButtonNew.Name = "ButtonNew";
			this.ButtonNew.Size = new System.Drawing.Size(149, 41);
			this.ButtonNew.TabIndex = 1;
			this.ButtonNew.Text = "作成";
			this.ButtonNew.UseVisualStyleBackColor = true;
			this.ButtonNew.Click += new System.EventHandler(this.ButtonNew_Click);
			// 
			// FormNew
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(334, 306);
			this.ControlBox = false;
			this.Controls.Add(this.ButtonNew);
			this.Name = "FormNew";
			this.Text = "新規作成";
			this.Controls.SetChildIndex(this.ButtonNew, 0);
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Button ButtonNew;
	}
}
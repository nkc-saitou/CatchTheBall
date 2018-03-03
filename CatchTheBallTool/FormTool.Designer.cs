namespace CatchTheBallTool {
	partial class FormTool {
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
			this.FlowLayout = new System.Windows.Forms.FlowLayoutPanel();
			this.SuspendLayout();
			// 
			// FlowLayout
			// 
			this.FlowLayout.Dock = System.Windows.Forms.DockStyle.Fill;
			this.FlowLayout.Location = new System.Drawing.Point(0, 0);
			this.FlowLayout.Name = "FlowLayout";
			this.FlowLayout.Size = new System.Drawing.Size(284, 261);
			this.FlowLayout.TabIndex = 0;
			// 
			// FormTool
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(284, 261);
			this.Controls.Add(this.FlowLayout);
			this.Name = "FormTool";
			this.Text = "ツール";
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.FlowLayoutPanel FlowLayout;
	}
}
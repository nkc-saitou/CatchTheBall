namespace CatchTheBallTool {
	partial class FormResizableWindow {
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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormResizableWindow));
			this.Status = new System.Windows.Forms.StatusStrip();
			this.StatusButton = new System.Windows.Forms.ToolStripDropDownButton();
			this.StatusZoom400 = new System.Windows.Forms.ToolStripMenuItem();
			this.StatusZoom200 = new System.Windows.Forms.ToolStripMenuItem();
			this.StatusZoom100 = new System.Windows.Forms.ToolStripMenuItem();
			this.StatusZoom50 = new System.Windows.Forms.ToolStripMenuItem();
			this.StatusZoom25 = new System.Windows.Forms.ToolStripMenuItem();
			this.Status.SuspendLayout();
			this.SuspendLayout();
			// 
			// Status
			// 
			this.Status.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.StatusButton});
			this.Status.Location = new System.Drawing.Point(0, 239);
			this.Status.Name = "Status";
			this.Status.Size = new System.Drawing.Size(284, 22);
			this.Status.TabIndex = 3;
			this.Status.Text = "statusStrip1";
			// 
			// StatusButton
			// 
			this.StatusButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
			this.StatusButton.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.StatusZoom400,
            this.StatusZoom200,
            this.StatusZoom100,
            this.StatusZoom50,
            this.StatusZoom25});
			this.StatusButton.Image = ((System.Drawing.Image)(resources.GetObject("StatusButton.Image")));
			this.StatusButton.ImageTransparentColor = System.Drawing.Color.Magenta;
			this.StatusButton.Name = "StatusButton";
			this.StatusButton.Size = new System.Drawing.Size(48, 20);
			this.StatusButton.Text = "100%";
			this.StatusButton.DropDownItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.StatusButton_DropDownItemClicked);
			// 
			// StatusZoom400
			// 
			this.StatusZoom400.Name = "StatusZoom400";
			this.StatusZoom400.Size = new System.Drawing.Size(152, 22);
			this.StatusZoom400.Tag = "4.0";
			this.StatusZoom400.Text = "400%";
			// 
			// StatusZoom200
			// 
			this.StatusZoom200.Name = "StatusZoom200";
			this.StatusZoom200.Size = new System.Drawing.Size(152, 22);
			this.StatusZoom200.Tag = "2.0";
			this.StatusZoom200.Text = "200%";
			// 
			// StatusZoom100
			// 
			this.StatusZoom100.Name = "StatusZoom100";
			this.StatusZoom100.Size = new System.Drawing.Size(152, 22);
			this.StatusZoom100.Tag = "1.0";
			this.StatusZoom100.Text = "100%";
			// 
			// StatusZoom50
			// 
			this.StatusZoom50.Name = "StatusZoom50";
			this.StatusZoom50.Size = new System.Drawing.Size(152, 22);
			this.StatusZoom50.Tag = "0.5";
			this.StatusZoom50.Text = "50%";
			// 
			// StatusZoom25
			// 
			this.StatusZoom25.Name = "StatusZoom25";
			this.StatusZoom25.Size = new System.Drawing.Size(152, 22);
			this.StatusZoom25.Tag = "0.25";
			this.StatusZoom25.Text = "25%";
			// 
			// FormResizableWindow
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(284, 261);
			this.Controls.Add(this.Status);
			this.Name = "FormResizableWindow";
			this.Text = "FormResizableWindow";
			this.Status.ResumeLayout(false);
			this.Status.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.StatusStrip Status;
		private System.Windows.Forms.ToolStripDropDownButton StatusButton;
		private System.Windows.Forms.ToolStripMenuItem StatusZoom400;
		private System.Windows.Forms.ToolStripMenuItem StatusZoom200;
		private System.Windows.Forms.ToolStripMenuItem StatusZoom100;
		private System.Windows.Forms.ToolStripMenuItem StatusZoom50;
		private System.Windows.Forms.ToolStripMenuItem StatusZoom25;
	}
}
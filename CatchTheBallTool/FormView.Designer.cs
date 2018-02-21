namespace CatchTheBallTool {
	partial class FormView {
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
			this.TabControlView = new System.Windows.Forms.TabControl();
			this.TabPreview = new System.Windows.Forms.TabPage();
			this.PictureBoxView = new System.Windows.Forms.PictureBox();
			this.TabMapping = new System.Windows.Forms.TabPage();
			this.TabEvent = new System.Windows.Forms.TabPage();
			this.TabControlView.SuspendLayout();
			this.TabPreview.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.PictureBoxView)).BeginInit();
			this.SuspendLayout();
			// 
			// TabControlView
			// 
			this.TabControlView.Controls.Add(this.TabPreview);
			this.TabControlView.Controls.Add(this.TabMapping);
			this.TabControlView.Controls.Add(this.TabEvent);
			this.TabControlView.Dock = System.Windows.Forms.DockStyle.Fill;
			this.TabControlView.Font = new System.Drawing.Font("MS UI Gothic", 12F);
			this.TabControlView.Location = new System.Drawing.Point(0, 0);
			this.TabControlView.Name = "TabControlView";
			this.TabControlView.SelectedIndex = 0;
			this.TabControlView.Size = new System.Drawing.Size(682, 454);
			this.TabControlView.TabIndex = 4;
			// 
			// TabPreview
			// 
			this.TabPreview.Controls.Add(this.PictureBoxView);
			this.TabPreview.Location = new System.Drawing.Point(4, 26);
			this.TabPreview.Name = "TabPreview";
			this.TabPreview.Padding = new System.Windows.Forms.Padding(3);
			this.TabPreview.Size = new System.Drawing.Size(674, 424);
			this.TabPreview.TabIndex = 0;
			this.TabPreview.Text = "プレビュー";
			this.TabPreview.UseVisualStyleBackColor = true;
			// 
			// PictureBoxView
			// 
			this.PictureBoxView.Location = new System.Drawing.Point(3, 3);
			this.PictureBoxView.Name = "PictureBoxView";
			this.PictureBoxView.Size = new System.Drawing.Size(100, 50);
			this.PictureBoxView.TabIndex = 0;
			this.PictureBoxView.TabStop = false;
			// 
			// TabMapping
			// 
			this.TabMapping.Location = new System.Drawing.Point(4, 26);
			this.TabMapping.Name = "TabMapping";
			this.TabMapping.Padding = new System.Windows.Forms.Padding(3);
			this.TabMapping.Size = new System.Drawing.Size(674, 424);
			this.TabMapping.TabIndex = 1;
			this.TabMapping.Text = "マップチップ配置";
			this.TabMapping.UseVisualStyleBackColor = true;
			// 
			// TabEvent
			// 
			this.TabEvent.Location = new System.Drawing.Point(4, 26);
			this.TabEvent.Name = "TabEvent";
			this.TabEvent.Size = new System.Drawing.Size(674, 424);
			this.TabEvent.TabIndex = 2;
			this.TabEvent.Text = "キャラクター";
			this.TabEvent.UseVisualStyleBackColor = true;
			// 
			// FormView
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(682, 476);
			this.Controls.Add(this.TabControlView);
			this.Name = "FormView";
			this.Text = "ビュー";
			this.Load += new System.EventHandler(this.FormView_Load);
			this.Controls.SetChildIndex(this.TabControlView, 0);
			this.TabControlView.ResumeLayout(false);
			this.TabPreview.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.PictureBoxView)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TabControl TabControlView;
		private System.Windows.Forms.TabPage TabPreview;
		private System.Windows.Forms.TabPage TabMapping;
		private System.Windows.Forms.TabPage TabEvent;
		private System.Windows.Forms.PictureBox PictureBoxView;
	}
}
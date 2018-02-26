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
			this.PictureBoxPreview = new System.Windows.Forms.PictureBox();
			this.TabMapping = new System.Windows.Forms.TabPage();
			this.PictureBoxMapChip = new System.Windows.Forms.PictureBox();
			this.TabObject = new System.Windows.Forms.TabPage();
			this.PictureBoxObject = new System.Windows.Forms.PictureBox();
			this.TabControlView.SuspendLayout();
			this.TabPreview.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.PictureBoxPreview)).BeginInit();
			this.TabMapping.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.PictureBoxMapChip)).BeginInit();
			this.TabObject.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.PictureBoxObject)).BeginInit();
			this.SuspendLayout();
			// 
			// TabControlView
			// 
			this.TabControlView.Controls.Add(this.TabPreview);
			this.TabControlView.Controls.Add(this.TabMapping);
			this.TabControlView.Controls.Add(this.TabObject);
			this.TabControlView.Dock = System.Windows.Forms.DockStyle.Fill;
			this.TabControlView.Font = new System.Drawing.Font("MS UI Gothic", 12F);
			this.TabControlView.Location = new System.Drawing.Point(0, 0);
			this.TabControlView.Name = "TabControlView";
			this.TabControlView.SelectedIndex = 0;
			this.TabControlView.Size = new System.Drawing.Size(682, 454);
			this.TabControlView.TabIndex = 4;
			this.TabControlView.SelectedIndexChanged += new System.EventHandler(this.TabControlView_SelectedIndexChanged);
			// 
			// TabPreview
			// 
			this.TabPreview.Controls.Add(this.PictureBoxPreview);
			this.TabPreview.Location = new System.Drawing.Point(4, 26);
			this.TabPreview.Name = "TabPreview";
			this.TabPreview.Size = new System.Drawing.Size(674, 424);
			this.TabPreview.TabIndex = 0;
			this.TabPreview.Text = "プレビュー";
			this.TabPreview.UseVisualStyleBackColor = true;
			// 
			// PictureBoxPreview
			// 
			this.PictureBoxPreview.Dock = System.Windows.Forms.DockStyle.Fill;
			this.PictureBoxPreview.Location = new System.Drawing.Point(0, 0);
			this.PictureBoxPreview.Name = "PictureBoxPreview";
			this.PictureBoxPreview.Size = new System.Drawing.Size(674, 424);
			this.PictureBoxPreview.TabIndex = 0;
			this.PictureBoxPreview.TabStop = false;
			this.PictureBoxPreview.MouseDown += new System.Windows.Forms.MouseEventHandler(this.PictureBoxPreview_MouseDown);
			// 
			// TabMapping
			// 
			this.TabMapping.Controls.Add(this.PictureBoxMapChip);
			this.TabMapping.Location = new System.Drawing.Point(4, 26);
			this.TabMapping.Name = "TabMapping";
			this.TabMapping.Size = new System.Drawing.Size(674, 424);
			this.TabMapping.TabIndex = 1;
			this.TabMapping.Text = "マップチップ配置";
			this.TabMapping.UseVisualStyleBackColor = true;
			// 
			// PictureBoxMapChip
			// 
			this.PictureBoxMapChip.Dock = System.Windows.Forms.DockStyle.Fill;
			this.PictureBoxMapChip.Location = new System.Drawing.Point(0, 0);
			this.PictureBoxMapChip.Name = "PictureBoxMapChip";
			this.PictureBoxMapChip.Size = new System.Drawing.Size(674, 424);
			this.PictureBoxMapChip.TabIndex = 1;
			this.PictureBoxMapChip.TabStop = false;
			this.PictureBoxMapChip.MouseDown += new System.Windows.Forms.MouseEventHandler(this.PictureBoxMapChip_MouseDown);
			// 
			// TabObject
			// 
			this.TabObject.Controls.Add(this.PictureBoxObject);
			this.TabObject.Location = new System.Drawing.Point(4, 26);
			this.TabObject.Name = "TabObject";
			this.TabObject.Size = new System.Drawing.Size(674, 424);
			this.TabObject.TabIndex = 2;
			this.TabObject.Text = "オブジェクト";
			this.TabObject.UseVisualStyleBackColor = true;
			// 
			// PictureBoxObject
			// 
			this.PictureBoxObject.Dock = System.Windows.Forms.DockStyle.Fill;
			this.PictureBoxObject.Location = new System.Drawing.Point(0, 0);
			this.PictureBoxObject.Name = "PictureBoxObject";
			this.PictureBoxObject.Size = new System.Drawing.Size(674, 424);
			this.PictureBoxObject.TabIndex = 1;
			this.PictureBoxObject.TabStop = false;
			this.PictureBoxObject.MouseDown += new System.Windows.Forms.MouseEventHandler(this.PictureBoxObject_MouseDown);
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
			this.SizeChanged += new System.EventHandler(this.FormView_SizeChanged);
			this.Controls.SetChildIndex(this.TabControlView, 0);
			this.TabControlView.ResumeLayout(false);
			this.TabPreview.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.PictureBoxPreview)).EndInit();
			this.TabMapping.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.PictureBoxMapChip)).EndInit();
			this.TabObject.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.PictureBoxObject)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TabControl TabControlView;
		private System.Windows.Forms.TabPage TabPreview;
		private System.Windows.Forms.TabPage TabMapping;
		private System.Windows.Forms.TabPage TabObject;
		private System.Windows.Forms.PictureBox PictureBoxPreview;
		private System.Windows.Forms.PictureBox PictureBoxMapChip;
		private System.Windows.Forms.PictureBox PictureBoxObject;
	}
}
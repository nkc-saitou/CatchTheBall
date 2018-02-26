namespace CatchTheBallTool {
	partial class FormMapChip {
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		/// <param name="disposing">マネージ リソースを破棄する場合は true を指定し、その他の場合は false を指定します。</param>
		protected override void Dispose(bool disposing) {
			if(disposing && (components != null)) {
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows フォーム デザイナーで生成されたコード

		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		private void InitializeComponent() {
			this.PictureBoxView = new System.Windows.Forms.PictureBox();
			((System.ComponentModel.ISupportInitialize)(this.PictureBoxView)).BeginInit();
			this.SuspendLayout();
			// 
			// PictureBoxView
			// 
			this.PictureBoxView.Dock = System.Windows.Forms.DockStyle.Fill;
			this.PictureBoxView.Location = new System.Drawing.Point(0, 0);
			this.PictureBoxView.Name = "PictureBoxView";
			this.PictureBoxView.Size = new System.Drawing.Size(533, 412);
			this.PictureBoxView.TabIndex = 0;
			this.PictureBoxView.TabStop = false;
			// 
			// FormMapChip
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
			this.ClientSize = new System.Drawing.Size(533, 434);
			this.Controls.Add(this.PictureBoxView);
			this.Name = "FormMapChip";
			this.Text = "マップチップ";
			this.Controls.SetChildIndex(this.PictureBoxView, 0);
			((System.ComponentModel.ISupportInitialize)(this.PictureBoxView)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.PictureBox PictureBoxView;
	}
}

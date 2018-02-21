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
			this.MapChipPictureBox = new System.Windows.Forms.PictureBox();
			((System.ComponentModel.ISupportInitialize)(this.MapChipPictureBox)).BeginInit();
			this.SuspendLayout();
			// 
			// MapChipPictureBox
			// 
			this.MapChipPictureBox.Location = new System.Drawing.Point(12, 12);
			this.MapChipPictureBox.Name = "MapChipPictureBox";
			this.MapChipPictureBox.Size = new System.Drawing.Size(283, 248);
			this.MapChipPictureBox.TabIndex = 0;
			this.MapChipPictureBox.TabStop = false;
			// 
			// FormMapChip
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
			this.ClientSize = new System.Drawing.Size(533, 434);
			this.Controls.Add(this.MapChipPictureBox);
			this.Name = "FormMapChip";
			this.Text = "マップチップ";
			this.Controls.SetChildIndex(this.MapChipPictureBox, 0);
			((System.ComponentModel.ISupportInitialize)(this.MapChipPictureBox)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.PictureBox MapChipPictureBox;
	}
}

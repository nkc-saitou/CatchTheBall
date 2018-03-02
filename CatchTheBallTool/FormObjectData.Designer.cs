namespace CatchTheBallTool {
	partial class FormObjectData {
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
			this.DataGridObjectData = new System.Windows.Forms.DataGridView();
			this.Number = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.ObjectIcon = new System.Windows.Forms.DataGridViewImageColumn();
			this.ObjectCount = new System.Windows.Forms.DataGridViewTextBoxColumn();
			((System.ComponentModel.ISupportInitialize)(this.DataGridObjectData)).BeginInit();
			this.SuspendLayout();
			// 
			// DataGridObjectData
			// 
			this.DataGridObjectData.ColumnHeadersHeight = 20;
			this.DataGridObjectData.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Number,
            this.ObjectIcon,
            this.ObjectCount});
			this.DataGridObjectData.Dock = System.Windows.Forms.DockStyle.Fill;
			this.DataGridObjectData.Location = new System.Drawing.Point(0, 0);
			this.DataGridObjectData.Name = "DataGridObjectData";
			this.DataGridObjectData.ReadOnly = true;
			this.DataGridObjectData.RightToLeft = System.Windows.Forms.RightToLeft.No;
			this.DataGridObjectData.RowHeadersVisible = false;
			this.DataGridObjectData.RowHeadersWidthSizeMode = System.Windows.Forms.DataGridViewRowHeadersWidthSizeMode.AutoSizeToAllHeaders;
			this.DataGridObjectData.RowTemplate.Height = 21;
			this.DataGridObjectData.Size = new System.Drawing.Size(418, 340);
			this.DataGridObjectData.TabIndex = 0;
			this.DataGridObjectData.TabStop = false;
			// 
			// Number
			// 
			this.Number.FillWeight = 40F;
			this.Number.Frozen = true;
			this.Number.HeaderText = "番号";
			this.Number.Name = "Number";
			this.Number.ReadOnly = true;
			this.Number.Width = 40;
			// 
			// ObjectIcon
			// 
			this.ObjectIcon.Frozen = true;
			this.ObjectIcon.HeaderText = "アイコン";
			this.ObjectIcon.ImageLayout = System.Windows.Forms.DataGridViewImageCellLayout.Zoom;
			this.ObjectIcon.Name = "ObjectIcon";
			this.ObjectIcon.ReadOnly = true;
			this.ObjectIcon.Resizable = System.Windows.Forms.DataGridViewTriState.True;
			this.ObjectIcon.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
			// 
			// ObjectCount
			// 
			this.ObjectCount.HeaderText = "カウント";
			this.ObjectCount.Name = "ObjectCount";
			this.ObjectCount.ReadOnly = true;
			// 
			// FormObjectData
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.AutoScroll = true;
			this.ClientSize = new System.Drawing.Size(418, 340);
			this.Controls.Add(this.DataGridObjectData);
			this.Name = "FormObjectData";
			this.Text = "オブジェクトデータ";
			((System.ComponentModel.ISupportInitialize)(this.DataGridObjectData)).EndInit();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.DataGridView DataGridObjectData;
		private System.Windows.Forms.DataGridViewTextBoxColumn Number;
		private System.Windows.Forms.DataGridViewImageColumn ObjectIcon;
		private System.Windows.Forms.DataGridViewTextBoxColumn ObjectCount;
	}
}
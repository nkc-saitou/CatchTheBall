namespace CatchTheBallTool {
	partial class FormMain {
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
			this.MenuMain = new System.Windows.Forms.MenuStrip();
			this.ファイルToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.新規ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.開くToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
			this.上書き保存SToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.名前を付けて保存AToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
			this.閉じるXToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.編集EToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.元に戻すUToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.やり直しRToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.ウィンドウWToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.ビューVToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.マップチップMToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.設定SToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.ウィンドウレイアウトToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.デフォルトレイアウトを復元ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.ユーザーレイアウトの保存ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.ヘルプHToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.dockPanelSuiteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.DockPanelMain = new WeifenLuo.WinFormsUI.Docking.DockPanel();
			this.SaveLayoutDialog = new System.Windows.Forms.SaveFileDialog();
			this.OpenLayoutDialog = new System.Windows.Forms.OpenFileDialog();
			this.ユーザーレイアウトの読み込みToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.MenuMain.SuspendLayout();
			this.SuspendLayout();
			// 
			// MenuMain
			// 
			this.MenuMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.ファイルToolStripMenuItem,
            this.編集EToolStripMenuItem,
            this.ウィンドウWToolStripMenuItem,
            this.ウィンドウレイアウトToolStripMenuItem,
            this.ヘルプHToolStripMenuItem});
			this.MenuMain.Location = new System.Drawing.Point(0, 0);
			this.MenuMain.Name = "MenuMain";
			this.MenuMain.Size = new System.Drawing.Size(1008, 24);
			this.MenuMain.TabIndex = 0;
			this.MenuMain.Text = "menuStrip1";
			// 
			// ファイルToolStripMenuItem
			// 
			this.ファイルToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.新規ToolStripMenuItem,
            this.開くToolStripMenuItem,
            this.toolStripSeparator1,
            this.上書き保存SToolStripMenuItem,
            this.名前を付けて保存AToolStripMenuItem,
            this.toolStripSeparator2,
            this.閉じるXToolStripMenuItem});
			this.ファイルToolStripMenuItem.Name = "ファイルToolStripMenuItem";
			this.ファイルToolStripMenuItem.Size = new System.Drawing.Size(66, 20);
			this.ファイルToolStripMenuItem.Text = "ファイル(&F)";
			// 
			// 新規ToolStripMenuItem
			// 
			this.新規ToolStripMenuItem.Name = "新規ToolStripMenuItem";
			this.新規ToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.N)));
			this.新規ToolStripMenuItem.Size = new System.Drawing.Size(257, 22);
			this.新規ToolStripMenuItem.Text = "新規(&F)...";
			this.新規ToolStripMenuItem.Click += new System.EventHandler(this.新規ToolStripMenuItem_Click);
			// 
			// 開くToolStripMenuItem
			// 
			this.開くToolStripMenuItem.Name = "開くToolStripMenuItem";
			this.開くToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
			this.開くToolStripMenuItem.Size = new System.Drawing.Size(257, 22);
			this.開くToolStripMenuItem.Text = "開く(&O)...";
			this.開くToolStripMenuItem.Click += new System.EventHandler(this.開くToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this.toolStripSeparator1.Name = "toolStripSeparator1";
			this.toolStripSeparator1.Size = new System.Drawing.Size(254, 6);
			// 
			// 上書き保存SToolStripMenuItem
			// 
			this.上書き保存SToolStripMenuItem.Name = "上書き保存SToolStripMenuItem";
			this.上書き保存SToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
			this.上書き保存SToolStripMenuItem.Size = new System.Drawing.Size(257, 22);
			this.上書き保存SToolStripMenuItem.Text = "上書き保存(&S)";
			this.上書き保存SToolStripMenuItem.Click += new System.EventHandler(this.上書き保存SToolStripMenuItem_Click);
			// 
			// 名前を付けて保存AToolStripMenuItem
			// 
			this.名前を付けて保存AToolStripMenuItem.Name = "名前を付けて保存AToolStripMenuItem";
			this.名前を付けて保存AToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift) 
            | System.Windows.Forms.Keys.S)));
			this.名前を付けて保存AToolStripMenuItem.Size = new System.Drawing.Size(257, 22);
			this.名前を付けて保存AToolStripMenuItem.Text = "名前を付けて保存(&A)...";
			this.名前を付けて保存AToolStripMenuItem.Click += new System.EventHandler(this.名前を付けて保存AToolStripMenuItem_Click);
			// 
			// toolStripSeparator2
			// 
			this.toolStripSeparator2.Name = "toolStripSeparator2";
			this.toolStripSeparator2.Size = new System.Drawing.Size(254, 6);
			// 
			// 閉じるXToolStripMenuItem
			// 
			this.閉じるXToolStripMenuItem.Name = "閉じるXToolStripMenuItem";
			this.閉じるXToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.W)));
			this.閉じるXToolStripMenuItem.Size = new System.Drawing.Size(257, 22);
			this.閉じるXToolStripMenuItem.Text = "閉じる(&X)";
			this.閉じるXToolStripMenuItem.Click += new System.EventHandler(this.閉じるXToolStripMenuItem_Click);
			// 
			// 編集EToolStripMenuItem
			// 
			this.編集EToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.元に戻すUToolStripMenuItem,
            this.やり直しRToolStripMenuItem});
			this.編集EToolStripMenuItem.Name = "編集EToolStripMenuItem";
			this.編集EToolStripMenuItem.Size = new System.Drawing.Size(57, 20);
			this.編集EToolStripMenuItem.Text = "編集(&E)";
			// 
			// 元に戻すUToolStripMenuItem
			// 
			this.元に戻すUToolStripMenuItem.Name = "元に戻すUToolStripMenuItem";
			this.元に戻すUToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Z)));
			this.元に戻すUToolStripMenuItem.Size = new System.Drawing.Size(173, 22);
			this.元に戻すUToolStripMenuItem.Text = "元に戻す(&U)";
			this.元に戻すUToolStripMenuItem.Click += new System.EventHandler(this.元に戻すUToolStripMenuItem_Click);
			// 
			// やり直しRToolStripMenuItem
			// 
			this.やり直しRToolStripMenuItem.Name = "やり直しRToolStripMenuItem";
			this.やり直しRToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Y)));
			this.やり直しRToolStripMenuItem.Size = new System.Drawing.Size(173, 22);
			this.やり直しRToolStripMenuItem.Text = "やり直し(&R)";
			this.やり直しRToolStripMenuItem.Click += new System.EventHandler(this.やり直しRToolStripMenuItem_Click);
			// 
			// ウィンドウWToolStripMenuItem
			// 
			this.ウィンドウWToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.ビューVToolStripMenuItem,
            this.マップチップMToolStripMenuItem,
            this.設定SToolStripMenuItem});
			this.ウィンドウWToolStripMenuItem.Name = "ウィンドウWToolStripMenuItem";
			this.ウィンドウWToolStripMenuItem.Size = new System.Drawing.Size(79, 20);
			this.ウィンドウWToolStripMenuItem.Text = "ウィンドウ(&W)";
			// 
			// ビューVToolStripMenuItem
			// 
			this.ビューVToolStripMenuItem.Name = "ビューVToolStripMenuItem";
			this.ビューVToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
			this.ビューVToolStripMenuItem.Text = "ビュー(&V)";
			this.ビューVToolStripMenuItem.Click += new System.EventHandler(this.ビューVToolStripMenuItem_Click);
			// 
			// マップチップMToolStripMenuItem
			// 
			this.マップチップMToolStripMenuItem.Name = "マップチップMToolStripMenuItem";
			this.マップチップMToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
			this.マップチップMToolStripMenuItem.Text = "マップチップ(&M)";
			this.マップチップMToolStripMenuItem.Click += new System.EventHandler(this.マップチップMToolStripMenuItem_Click);
			// 
			// 設定SToolStripMenuItem
			// 
			this.設定SToolStripMenuItem.Name = "設定SToolStripMenuItem";
			this.設定SToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
			this.設定SToolStripMenuItem.Text = "設定(&S)";
			this.設定SToolStripMenuItem.Click += new System.EventHandler(this.設定SToolStripMenuItem_Click);
			// 
			// ウィンドウレイアウトToolStripMenuItem
			// 
			this.ウィンドウレイアウトToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.デフォルトレイアウトを復元ToolStripMenuItem,
            this.ユーザーレイアウトの保存ToolStripMenuItem,
            this.ユーザーレイアウトの読み込みToolStripMenuItem});
			this.ウィンドウレイアウトToolStripMenuItem.Name = "ウィンドウレイアウトToolStripMenuItem";
			this.ウィンドウレイアウトToolStripMenuItem.Size = new System.Drawing.Size(104, 20);
			this.ウィンドウレイアウトToolStripMenuItem.Text = "ウィンドウレイアウト";
			// 
			// デフォルトレイアウトを復元ToolStripMenuItem
			// 
			this.デフォルトレイアウトを復元ToolStripMenuItem.Name = "デフォルトレイアウトを復元ToolStripMenuItem";
			this.デフォルトレイアウトを復元ToolStripMenuItem.Size = new System.Drawing.Size(194, 22);
			this.デフォルトレイアウトを復元ToolStripMenuItem.Text = "デフォルトレイアウトを復元";
			this.デフォルトレイアウトを復元ToolStripMenuItem.Click += new System.EventHandler(this.デフォルトレイアウトを復元ToolStripMenuItem_Click);
			// 
			// ユーザーレイアウトの保存ToolStripMenuItem
			// 
			this.ユーザーレイアウトの保存ToolStripMenuItem.Name = "ユーザーレイアウトの保存ToolStripMenuItem";
			this.ユーザーレイアウトの保存ToolStripMenuItem.Size = new System.Drawing.Size(194, 22);
			this.ユーザーレイアウトの保存ToolStripMenuItem.Text = "ユーザーレイアウトの保存";
			this.ユーザーレイアウトの保存ToolStripMenuItem.Click += new System.EventHandler(this.ユーザーレイアウトの保存ToolStripMenuItem_Click);
			// 
			// ヘルプHToolStripMenuItem
			// 
			this.ヘルプHToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.dockPanelSuiteToolStripMenuItem});
			this.ヘルプHToolStripMenuItem.Name = "ヘルプHToolStripMenuItem";
			this.ヘルプHToolStripMenuItem.Size = new System.Drawing.Size(65, 20);
			this.ヘルプHToolStripMenuItem.Text = "ヘルプ(&H)";
			// 
			// dockPanelSuiteToolStripMenuItem
			// 
			this.dockPanelSuiteToolStripMenuItem.Name = "dockPanelSuiteToolStripMenuItem";
			this.dockPanelSuiteToolStripMenuItem.Size = new System.Drawing.Size(165, 22);
			this.dockPanelSuiteToolStripMenuItem.Text = "DockPanelSuite...";
			this.dockPanelSuiteToolStripMenuItem.Click += new System.EventHandler(this.dockPanelSuiteToolStripMenuItem_Click);
			// 
			// DockPanelMain
			// 
			this.DockPanelMain.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
			this.DockPanelMain.Dock = System.Windows.Forms.DockStyle.Fill;
			this.DockPanelMain.Location = new System.Drawing.Point(0, 24);
			this.DockPanelMain.Name = "DockPanelMain";
			this.DockPanelMain.Size = new System.Drawing.Size(1008, 705);
			this.DockPanelMain.TabIndex = 1;
			// 
			// SaveLayoutDialog
			// 
			this.SaveLayoutDialog.DefaultExt = "xml";
			this.SaveLayoutDialog.FileName = "userLayout";
			this.SaveLayoutDialog.Filter = "レイアウト|*.xml";
			this.SaveLayoutDialog.Title = "レイアウトを保存";
			// 
			// OpenLayoutDialog
			// 
			this.OpenLayoutDialog.DefaultExt = "xml";
			this.OpenLayoutDialog.FileName = "openFileDialog1";
			this.OpenLayoutDialog.Filter = "レイアウト|*.xml";
			this.OpenLayoutDialog.Title = "レイアウトを読み込み";
			// 
			// ユーザーレイアウトの読み込みToolStripMenuItem
			// 
			this.ユーザーレイアウトの読み込みToolStripMenuItem.Name = "ユーザーレイアウトの読み込みToolStripMenuItem";
			this.ユーザーレイアウトの読み込みToolStripMenuItem.Size = new System.Drawing.Size(210, 22);
			this.ユーザーレイアウトの読み込みToolStripMenuItem.Text = "ユーザーレイアウトの読み込み";
			this.ユーザーレイアウトの読み込みToolStripMenuItem.Click += new System.EventHandler(this.ユーザーレイアウトの読み込みToolStripMenuItem_Click);
			// 
			// FormMain
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(1008, 729);
			this.Controls.Add(this.DockPanelMain);
			this.Controls.Add(this.MenuMain);
			this.IsMdiContainer = true;
			this.MainMenuStrip = this.MenuMain;
			this.Name = "FormMain";
			this.Text = "CatchTheBallStageTool";
			this.Load += new System.EventHandler(this.FormMain_Load);
			this.MenuMain.ResumeLayout(false);
			this.MenuMain.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.MenuStrip MenuMain;
		private System.Windows.Forms.ToolStripMenuItem ファイルToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem 新規ToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem 開くToolStripMenuItem;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
		private System.Windows.Forms.ToolStripMenuItem 上書き保存SToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem 名前を付けて保存AToolStripMenuItem;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
		private System.Windows.Forms.ToolStripMenuItem 閉じるXToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem 編集EToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem 元に戻すUToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem やり直しRToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem ウィンドウWToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem ウィンドウレイアウトToolStripMenuItem;
		private WeifenLuo.WinFormsUI.Docking.DockPanel DockPanelMain;
		private System.Windows.Forms.ToolStripMenuItem ビューVToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem マップチップMToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem 設定SToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem デフォルトレイアウトを復元ToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem ユーザーレイアウトの保存ToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem ヘルプHToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem dockPanelSuiteToolStripMenuItem;
		private System.Windows.Forms.SaveFileDialog SaveLayoutDialog;
		private System.Windows.Forms.OpenFileDialog OpenLayoutDialog;
		private System.Windows.Forms.ToolStripMenuItem ユーザーレイアウトの読み込みToolStripMenuItem;
	}
}


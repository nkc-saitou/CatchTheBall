﻿namespace CatchTheBallTool {
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
			this.ナビゲーションNToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.ツールTToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.ウィンドウレイアウトToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.デフォルトレイアウトを復元ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.ユーザーレイアウトの保存ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.ユーザーレイアウトの読み込みToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.ヘルプHToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.dockPanelSuiteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.DockPanelMain = new WeifenLuo.WinFormsUI.Docking.DockPanel();
			this.SaveLayoutDialog = new System.Windows.Forms.SaveFileDialog();
			this.OpenLayoutDialog = new System.Windows.Forms.OpenFileDialog();
			this.OpenFileStageData = new System.Windows.Forms.OpenFileDialog();
			this.SaveFileStageData = new System.Windows.Forms.SaveFileDialog();
			this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
			this.ステージデータの編集EToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
			this.画像としてビューを保存ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.SaveFileView = new System.Windows.Forms.SaveFileDialog();
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
            this.画像としてビューを保存ToolStripMenuItem,
            this.toolStripSeparator4,
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
            this.やり直しRToolStripMenuItem,
            this.toolStripSeparator3,
            this.ステージデータの編集EToolStripMenuItem});
			this.編集EToolStripMenuItem.Name = "編集EToolStripMenuItem";
			this.編集EToolStripMenuItem.Size = new System.Drawing.Size(57, 20);
			this.編集EToolStripMenuItem.Text = "編集(&E)";
			// 
			// 元に戻すUToolStripMenuItem
			// 
			this.元に戻すUToolStripMenuItem.Name = "元に戻すUToolStripMenuItem";
			this.元に戻すUToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Z)));
			this.元に戻すUToolStripMenuItem.Size = new System.Drawing.Size(193, 22);
			this.元に戻すUToolStripMenuItem.Text = "元に戻す(&U)";
			this.元に戻すUToolStripMenuItem.Click += new System.EventHandler(this.元に戻すUToolStripMenuItem_Click);
			// 
			// やり直しRToolStripMenuItem
			// 
			this.やり直しRToolStripMenuItem.Name = "やり直しRToolStripMenuItem";
			this.やり直しRToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Y)));
			this.やり直しRToolStripMenuItem.Size = new System.Drawing.Size(193, 22);
			this.やり直しRToolStripMenuItem.Text = "やり直し(&R)";
			this.やり直しRToolStripMenuItem.Click += new System.EventHandler(this.やり直しRToolStripMenuItem_Click);
			// 
			// ウィンドウWToolStripMenuItem
			// 
			this.ウィンドウWToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.ビューVToolStripMenuItem,
            this.マップチップMToolStripMenuItem,
            this.ナビゲーションNToolStripMenuItem,
            this.ツールTToolStripMenuItem});
			this.ウィンドウWToolStripMenuItem.Name = "ウィンドウWToolStripMenuItem";
			this.ウィンドウWToolStripMenuItem.Size = new System.Drawing.Size(79, 20);
			this.ウィンドウWToolStripMenuItem.Text = "ウィンドウ(&W)";
			// 
			// ビューVToolStripMenuItem
			// 
			this.ビューVToolStripMenuItem.Name = "ビューVToolStripMenuItem";
			this.ビューVToolStripMenuItem.Size = new System.Drawing.Size(151, 22);
			this.ビューVToolStripMenuItem.Text = "ビュー(&V)";
			// 
			// マップチップMToolStripMenuItem
			// 
			this.マップチップMToolStripMenuItem.Name = "マップチップMToolStripMenuItem";
			this.マップチップMToolStripMenuItem.Size = new System.Drawing.Size(151, 22);
			this.マップチップMToolStripMenuItem.Text = "マップチップ(&M)";
			// 
			// ナビゲーションNToolStripMenuItem
			// 
			this.ナビゲーションNToolStripMenuItem.Name = "ナビゲーションNToolStripMenuItem";
			this.ナビゲーションNToolStripMenuItem.Size = new System.Drawing.Size(151, 22);
			this.ナビゲーションNToolStripMenuItem.Text = "ナビゲーション(&N)";
			// 
			// ツールTToolStripMenuItem
			// 
			this.ツールTToolStripMenuItem.Name = "ツールTToolStripMenuItem";
			this.ツールTToolStripMenuItem.Size = new System.Drawing.Size(151, 22);
			this.ツールTToolStripMenuItem.Text = "ツール(&T)";
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
			this.デフォルトレイアウトを復元ToolStripMenuItem.Size = new System.Drawing.Size(210, 22);
			this.デフォルトレイアウトを復元ToolStripMenuItem.Text = "デフォルトレイアウトを復元";
			this.デフォルトレイアウトを復元ToolStripMenuItem.Click += new System.EventHandler(this.デフォルトレイアウトを復元ToolStripMenuItem_Click);
			// 
			// ユーザーレイアウトの保存ToolStripMenuItem
			// 
			this.ユーザーレイアウトの保存ToolStripMenuItem.Name = "ユーザーレイアウトの保存ToolStripMenuItem";
			this.ユーザーレイアウトの保存ToolStripMenuItem.Size = new System.Drawing.Size(210, 22);
			this.ユーザーレイアウトの保存ToolStripMenuItem.Text = "ユーザーレイアウトの保存";
			this.ユーザーレイアウトの保存ToolStripMenuItem.Click += new System.EventHandler(this.ユーザーレイアウトの保存ToolStripMenuItem_Click);
			// 
			// ユーザーレイアウトの読み込みToolStripMenuItem
			// 
			this.ユーザーレイアウトの読み込みToolStripMenuItem.Name = "ユーザーレイアウトの読み込みToolStripMenuItem";
			this.ユーザーレイアウトの読み込みToolStripMenuItem.Size = new System.Drawing.Size(210, 22);
			this.ユーザーレイアウトの読み込みToolStripMenuItem.Text = "ユーザーレイアウトの読み込み";
			this.ユーザーレイアウトの読み込みToolStripMenuItem.Click += new System.EventHandler(this.ユーザーレイアウトの読み込みToolStripMenuItem_Click);
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
			this.SaveLayoutDialog.FileName = "UserLayout";
			this.SaveLayoutDialog.Filter = "レイアウト|*.xml";
			this.SaveLayoutDialog.Title = "レイアウトを保存";
			// 
			// OpenLayoutDialog
			// 
			this.OpenLayoutDialog.DefaultExt = "xml";
			this.OpenLayoutDialog.FileName = "UserLayout";
			this.OpenLayoutDialog.Filter = "レイアウト|*.xml";
			this.OpenLayoutDialog.Title = "レイアウトを読み込み";
			// 
			// OpenFileStageData
			// 
			this.OpenFileStageData.FileName = "StageData";
			this.OpenFileStageData.Title = "ステージデータを開く";
			// 
			// SaveFileStageData
			// 
			this.SaveFileStageData.FileName = "StageData";
			this.SaveFileStageData.Title = "ステージデータを保存する";
			// 
			// toolStripSeparator3
			// 
			this.toolStripSeparator3.Name = "toolStripSeparator3";
			this.toolStripSeparator3.Size = new System.Drawing.Size(190, 6);
			// 
			// ステージデータの編集EToolStripMenuItem
			// 
			this.ステージデータの編集EToolStripMenuItem.Name = "ステージデータの編集EToolStripMenuItem";
			this.ステージデータの編集EToolStripMenuItem.Size = new System.Drawing.Size(193, 22);
			this.ステージデータの編集EToolStripMenuItem.Text = "ステージデータの編集(&E)...";
			this.ステージデータの編集EToolStripMenuItem.Click += new System.EventHandler(this.ステージデータの編集EToolStripMenuItem_Click);
			// 
			// toolStripSeparator4
			// 
			this.toolStripSeparator4.Name = "toolStripSeparator4";
			this.toolStripSeparator4.Size = new System.Drawing.Size(254, 6);
			// 
			// 画像としてビューを保存ToolStripMenuItem
			// 
			this.画像としてビューを保存ToolStripMenuItem.Name = "画像としてビューを保存ToolStripMenuItem";
			this.画像としてビューを保存ToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.S)));
			this.画像としてビューを保存ToolStripMenuItem.Size = new System.Drawing.Size(257, 22);
			this.画像としてビューを保存ToolStripMenuItem.Text = "画像としてビューを保存...";
			this.画像としてビューを保存ToolStripMenuItem.Click += new System.EventHandler(this.画像としてビューを保存ToolStripMenuItem_Click);
			// 
			// SaveFileView
			// 
			this.SaveFileView.DefaultExt = "png";
			this.SaveFileView.FileName = "View";
			this.SaveFileView.Filter = "PNGファイル|*.png|すべてのファイル|*.*";
			this.SaveFileView.Title = "画像としてビューを保存します";
			// 
			// FormMain
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(1008, 729);
			this.Controls.Add(this.DockPanelMain);
			this.Controls.Add(this.MenuMain);
			this.IsMdiContainer = true;
			this.KeyPreview = true;
			this.MainMenuStrip = this.MenuMain;
			this.Name = "FormMain";
			this.Text = "CatchTheBallStageTool";
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FormMain_FormClosing);
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
		private System.Windows.Forms.ToolStripMenuItem デフォルトレイアウトを復元ToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem ユーザーレイアウトの保存ToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem ヘルプHToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem dockPanelSuiteToolStripMenuItem;
		private System.Windows.Forms.SaveFileDialog SaveLayoutDialog;
		private System.Windows.Forms.OpenFileDialog OpenLayoutDialog;
		private System.Windows.Forms.ToolStripMenuItem ユーザーレイアウトの読み込みToolStripMenuItem;
		private System.Windows.Forms.OpenFileDialog OpenFileStageData;
		private System.Windows.Forms.SaveFileDialog SaveFileStageData;
		public System.Windows.Forms.ToolStripMenuItem ビューVToolStripMenuItem;
		public System.Windows.Forms.ToolStripMenuItem マップチップMToolStripMenuItem;
		public System.Windows.Forms.ToolStripMenuItem ナビゲーションNToolStripMenuItem;
		public System.Windows.Forms.ToolStripMenuItem ツールTToolStripMenuItem;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
		private System.Windows.Forms.ToolStripMenuItem ステージデータの編集EToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem 画像としてビューを保存ToolStripMenuItem;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
		private System.Windows.Forms.SaveFileDialog SaveFileView;
	}
}


using Gmail_Checker.Interfaces;
using System.Collections.Generic;

namespace Gmail_Checker.Classes
{
    partial class MessageForm1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MessageForm1));
            this.customSectorList1 = new Gmail_Checker.CustomSectorList();
            this.SuspendLayout();
            // 
            // customSectorList1
            // 
            this.customSectorList1.AutoScroll = true;
            this.customSectorList1.AutoSize = true;
            this.customSectorList1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(64)))));
            this.customSectorList1.Location = new System.Drawing.Point(1, 1);
            this.customSectorList1.MaximumSize = new System.Drawing.Size(750, 434);
            this.customSectorList1.Name = "customSectorList1";
            this.customSectorList1.Size = new System.Drawing.Size(750, 55);
            this.customSectorList1.TabIndex = 1;
            // 
            // MessageForm1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.ClientSize = new System.Drawing.Size(732, 57);
            this.Controls.Add(this.customSectorList1);
            this.DoubleBuffered = true;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximumSize = new System.Drawing.Size(750, 520);
            this.Name = "MessageForm1";
            this.Opacity = 0.9D;
            this.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Show;
            this.Text = "Unread Messages";
            this.Load += new System.EventHandler(this.MessageForm1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        public void LoadSectors(IDictionary<string,ICustomMessage> list)
        {
            customSectorList1.AddMyControls(list);
        }

        private CustomSectorList customSectorList1;
    }
}
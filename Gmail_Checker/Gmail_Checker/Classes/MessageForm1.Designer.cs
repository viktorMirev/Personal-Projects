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
            this.customSectorList1.Location = new System.Drawing.Point(3, 19);
            this.customSectorList1.Name = "customSectorList1";
            this.customSectorList1.Size = new System.Drawing.Size(825, 424);
            this.customSectorList1.TabIndex = 1;
            // 
            // MessageForm1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Silver;
            this.ClientSize = new System.Drawing.Size(832, 481);
            this.Controls.Add(this.customSectorList1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "MessageForm1";
            this.Text = "Unread Messages";
            this.ResumeLayout(false);

        }

        #endregion

        public void LoadSectors(IDictionary<string,ICustomMessage> list)
        {
            customSectorList1.AddMyControls(list);
        }

        private CustomSectorList customSectorList1;
    }
}
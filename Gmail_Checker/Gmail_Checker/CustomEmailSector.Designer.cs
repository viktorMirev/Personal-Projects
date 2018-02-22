namespace Gmail_Checker
{
    partial class CustomEmailSector
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.labelFrom = new System.Windows.Forms.Label();
            this.labelFromText = new System.Windows.Forms.Label();
            this.labelSubject = new System.Windows.Forms.Label();
            this.labelSubjectText = new System.Windows.Forms.Label();
            this.labelSnippet = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // labelFrom
            // 
            this.labelFrom.AutoSize = true;
            this.labelFrom.Location = new System.Drawing.Point(13, 11);
            this.labelFrom.Name = "labelFrom";
            this.labelFrom.Size = new System.Drawing.Size(70, 17);
            this.labelFrom.TabIndex = 2;
            this.labelFrom.Text = "labelFrom";
            // 
            // labelFromText
            // 
            this.labelFromText.AutoSize = true;
            this.labelFromText.Location = new System.Drawing.Point(109, 11);
            this.labelFromText.Name = "labelFromText";
            this.labelFromText.Size = new System.Drawing.Size(97, 17);
            this.labelFromText.TabIndex = 3;
            this.labelFromText.Text = "labelFromText";
            // 
            // labelSubject
            // 
            this.labelSubject.AutoSize = true;
            this.labelSubject.Location = new System.Drawing.Point(13, 40);
            this.labelSubject.Name = "labelSubject";
            this.labelSubject.Size = new System.Drawing.Size(85, 17);
            this.labelSubject.TabIndex = 4;
            this.labelSubject.Text = "labelSubject";
            // 
            // labelSubjectText
            // 
            this.labelSubjectText.AutoSize = true;
            this.labelSubjectText.Location = new System.Drawing.Point(109, 40);
            this.labelSubjectText.Name = "labelSubjectText";
            this.labelSubjectText.Size = new System.Drawing.Size(112, 17);
            this.labelSubjectText.TabIndex = 5;
            this.labelSubjectText.Text = "labelSubjectText";
            // 
            // labelSnippet
            // 
            this.labelSnippet.AutoSize = true;
            this.labelSnippet.Location = new System.Drawing.Point(13, 79);
            this.labelSnippet.Name = "labelSnippet";
            this.labelSnippet.Size = new System.Drawing.Size(56, 17);
            this.labelSnippet.TabIndex = 6;
            this.labelSnippet.Text = "Snippet";
            // 
            // CustomEmailSector
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlDark;
            this.Controls.Add(this.labelSnippet);
            this.Controls.Add(this.labelSubjectText);
            this.Controls.Add(this.labelSubject);
            this.Controls.Add(this.labelFromText);
            this.Controls.Add(this.labelFrom);
            this.Name = "CustomEmailSector";
            this.Size = new System.Drawing.Size(465, 133);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.Label labelFrom;
        private System.Windows.Forms.Label labelFromText;
        private System.Windows.Forms.Label labelSubject;
        private System.Windows.Forms.Label labelSubjectText;
        private System.Windows.Forms.Label labelSnippet;
    }
}

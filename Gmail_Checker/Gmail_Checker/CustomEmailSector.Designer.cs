using Gmail_Checker.Interfaces;

namespace Gmail_Checker
{
    partial class CustomEmailSector
    {
        private string content;
        private string subject;
        private string sender;
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
            this.Button_ShowFullMsg = new System.Windows.Forms.Button();
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
            this.labelFrom.Font = new System.Drawing.Font("Segoe UI Semibold", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelFrom.Location = new System.Drawing.Point(13, 11);
            this.labelFrom.Name = "labelFrom";
            this.labelFrom.Size = new System.Drawing.Size(52, 19);
            this.labelFrom.TabIndex = 2;
            this.labelFrom.Text = "Sender";
            // 
            // labelFromText
            // 
            this.labelFromText.AutoSize = true;
            this.labelFromText.Font = new System.Drawing.Font("Segoe UI Semibold", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelFromText.Location = new System.Drawing.Point(109, 11);
            this.labelFromText.Name = "labelFromText";
            this.labelFromText.Size = new System.Drawing.Size(145, 19);
            this.labelFromText.TabIndex = 3;
            this.labelFromText.Text = "example.exp@app.net";
            // 
            // labelSubject
            // 
            this.labelSubject.AutoSize = true;
            this.labelSubject.Font = new System.Drawing.Font("Segoe UI Semibold", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelSubject.Location = new System.Drawing.Point(13, 30);
            this.labelSubject.Name = "labelSubject";
            this.labelSubject.Size = new System.Drawing.Size(56, 19);
            this.labelSubject.TabIndex = 4;
            this.labelSubject.Text = "Subject";
            // 
            // labelSubjectText
            // 
            this.labelSubjectText.AutoSize = true;
            this.labelSubjectText.Font = new System.Drawing.Font("Segoe UI Semibold", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelSubjectText.Location = new System.Drawing.Point(109, 30);
            this.labelSubjectText.Name = "labelSubjectText";
            this.labelSubjectText.Size = new System.Drawing.Size(34, 19);
            this.labelSubjectText.TabIndex = 5;
            this.labelSubjectText.Text = "Test";
            // 
            // labelSnippet
            // 
            this.labelSnippet.AutoSize = true;
            this.labelSnippet.Font = new System.Drawing.Font("Segoe UI Semibold", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelSnippet.Location = new System.Drawing.Point(12, 60);
            this.labelSnippet.Name = "labelSnippet";
            this.labelSnippet.Size = new System.Drawing.Size(61, 20);
            this.labelSnippet.TabIndex = 6;
            this.labelSnippet.Text = "Snippet";
            // 
            // Button_ShowFullMsg
            // 
            this.Button_ShowFullMsg.BackColor = System.Drawing.Color.Silver;
            this.Button_ShowFullMsg.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Button_ShowFullMsg.Font = new System.Drawing.Font("Segoe UI Semibold", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Button_ShowFullMsg.Location = new System.Drawing.Point(484, 9);
            this.Button_ShowFullMsg.Name = "Button_ShowFullMsg";
            this.Button_ShowFullMsg.Size = new System.Drawing.Size(168, 30);
            this.Button_ShowFullMsg.TabIndex = 7;
            this.Button_ShowFullMsg.Text = "Show Full MSG";
            this.Button_ShowFullMsg.UseVisualStyleBackColor = false;
            this.Button_ShowFullMsg.Click += new System.EventHandler(this.Button_ShowFullMsg_Click);
            // 
            // CustomEmailSector
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Gray;
            this.Controls.Add(this.Button_ShowFullMsg);
            this.Controls.Add(this.labelSnippet);
            this.Controls.Add(this.labelSubjectText);
            this.Controls.Add(this.labelSubject);
            this.Controls.Add(this.labelFromText);
            this.Controls.Add(this.labelFrom);
            this.Name = "CustomEmailSector";
            this.Size = new System.Drawing.Size(700, 95);
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


        //to be modified for all 
        public void FillMessageData(ICustomMessage msg)
        {
            this.labelSnippet.Text = msg.Snippet;
            this.labelFromText.Text = msg.Sender;
            this.labelSubjectText.Text = msg.Subject;
            this.content = msg.Content;
            this.sender = msg.Sender;
            this.subject = msg.Subject;
        }

        private System.Windows.Forms.Button Button_ShowFullMsg;
    }
}

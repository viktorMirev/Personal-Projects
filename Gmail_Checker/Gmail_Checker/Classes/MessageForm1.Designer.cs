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
            this.BOX = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // BOX
            // 
            this.BOX.Location = new System.Drawing.Point(36, 32);
            this.BOX.Multiline = true;
            this.BOX.Name = "BOX";
            this.BOX.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.BOX.Size = new System.Drawing.Size(846, 428);
            this.BOX.TabIndex = 0;
            // 
            // MessageForm1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(919, 506);
            this.Controls.Add(this.BOX);
            this.Name = "MessageForm1";
            this.Text = "MessageForm1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox BOX;

        public void LoadMessages(string data)
        {
            this.BOX.Text = data;
        }
        

    }
}
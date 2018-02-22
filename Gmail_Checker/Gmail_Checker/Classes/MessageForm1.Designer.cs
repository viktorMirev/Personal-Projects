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
            this.Box = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // Box
            // 
            this.Box.Location = new System.Drawing.Point(12, 30);
            this.Box.Multiline = true;
            this.Box.Name = "Box";
            this.Box.Size = new System.Drawing.Size(660, 230);
            this.Box.TabIndex = 0;
            this.Box.Text = "dfdf";
            // 
            // MessageForm1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(815, 387);
            this.Controls.Add(this.Box);
            this.Name = "MessageForm1";
            this.Text = "MessageForm1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox Box;
    }
}
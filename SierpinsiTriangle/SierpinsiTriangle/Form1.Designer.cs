namespace SierpinsiTriangle
{
    partial class Form1
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
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.TextBoxSteps = new System.Windows.Forms.TextBox();
            this.drawIt = new System.Windows.Forms.Button();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.textBoxTop = new System.Windows.Forms.TextBox();
            this.textBoxLeftNRight = new System.Windows.Forms.TextBox();
            this.textBoxTilt = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.colorDialog2 = new System.Windows.Forms.ColorDialog();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(-133, 51);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(1080, 467);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Click += new System.EventHandler(this.PictureBox1_Click);
            // 
            // TextBoxSteps
            // 
            this.TextBoxSteps.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.TextBoxSteps.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TextBoxSteps.ForeColor = System.Drawing.Color.White;
            this.TextBoxSteps.Location = new System.Drawing.Point(250, 2);
            this.TextBoxSteps.Name = "TextBoxSteps";
            this.TextBoxSteps.Size = new System.Drawing.Size(122, 33);
            this.TextBoxSteps.TabIndex = 1;
            this.TextBoxSteps.Text = "15600";
            this.TextBoxSteps.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.TextBoxSteps.TextChanged += new System.EventHandler(this.TextBoxSteps_TextChanged);
            this.TextBoxSteps.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.TextBoxSteps_KeyPress);
            // 
            // drawIt
            // 
            this.drawIt.FlatAppearance.BorderSize = 0;
            this.drawIt.Font = new System.Drawing.Font("Segoe UI", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.drawIt.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.drawIt.Location = new System.Drawing.Point(12, 4);
            this.drawIt.Name = "drawIt";
            this.drawIt.Size = new System.Drawing.Size(113, 41);
            this.drawIt.TabIndex = 2;
            this.drawIt.Text = "Fractal It";
            this.drawIt.UseVisualStyleBackColor = true;
            this.drawIt.Click += new System.EventHandler(this.Button1_Click);
            // 
            // textBoxTop
            // 
            this.textBoxTop.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.textBoxTop.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBoxTop.ForeColor = System.Drawing.Color.White;
            this.textBoxTop.Location = new System.Drawing.Point(481, 2);
            this.textBoxTop.Name = "textBoxTop";
            this.textBoxTop.Size = new System.Drawing.Size(104, 33);
            this.textBoxTop.TabIndex = 3;
            this.textBoxTop.Text = "90";
            this.textBoxTop.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.textBoxTop.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.TextBoxTop_KeyPress);
            // 
            // textBoxLeftNRight
            // 
            this.textBoxLeftNRight.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.textBoxLeftNRight.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBoxLeftNRight.ForeColor = System.Drawing.Color.White;
            this.textBoxLeftNRight.Location = new System.Drawing.Point(690, 2);
            this.textBoxLeftNRight.Name = "textBoxLeftNRight";
            this.textBoxLeftNRight.Size = new System.Drawing.Size(104, 33);
            this.textBoxLeftNRight.TabIndex = 4;
            this.textBoxLeftNRight.Text = "260";
            this.textBoxLeftNRight.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.textBoxLeftNRight.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxLeftNRight_KeyPress);
            // 
            // textBoxTilt
            // 
            this.textBoxTilt.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.textBoxTilt.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBoxTilt.ForeColor = System.Drawing.Color.White;
            this.textBoxTilt.Location = new System.Drawing.Point(868, 2);
            this.textBoxTilt.Name = "textBoxTilt";
            this.textBoxTilt.Size = new System.Drawing.Size(104, 33);
            this.textBoxTilt.TabIndex = 5;
            this.textBoxTilt.Text = "0";
            this.textBoxTilt.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.textBoxTilt.TextChanged += new System.EventHandler(this.textBoxTilt_TextChanged);
            this.textBoxTilt.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxTilt_KeyPress);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(195, 3);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(49, 21);
            this.label1.TabIndex = 6;
            this.label1.Text = "Pixels";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(378, 3);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(97, 21);
            this.label2.TabIndex = 7;
            this.label2.Text = "TopNBottom";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.White;
            this.label3.Location = new System.Drawing.Point(606, 3);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(85, 21);
            this.label3.TabIndex = 8;
            this.label3.Text = "LeftNRight";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.Color.White;
            this.label4.Location = new System.Drawing.Point(831, 3);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(31, 21);
            this.label4.TabIndex = 9;
            this.label4.Text = "Tilt";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.ClientSize = new System.Drawing.Size(984, 741);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxTilt);
            this.Controls.Add(this.textBoxLeftNRight);
            this.Controls.Add(this.textBoxTop);
            this.Controls.Add(this.drawIt);
            this.Controls.Add(this.TextBoxSteps);
            this.Controls.Add(this.pictureBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Form1";
            this.Opacity = 0.95D;
            this.Text = "SIERPINSKI";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.TextBox TextBoxSteps;
        private System.Windows.Forms.Button drawIt;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.TextBox textBoxTop;
        private System.Windows.Forms.TextBox textBoxLeftNRight;
        private System.Windows.Forms.TextBox textBoxTilt;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ColorDialog colorDialog2;
    }
}


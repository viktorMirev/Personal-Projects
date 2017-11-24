namespace MyBalance
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.MirevBox = new System.Windows.Forms.TextBox();
            this.KosyoBox = new System.Windows.Forms.MaskedTextBox();
            this.Calculate = new System.Windows.Forms.Button();
            this.MirevLabel = new System.Windows.Forms.Label();
            this.KoseLabel = new System.Windows.Forms.Label();
            this.DifferenceLabel = new System.Windows.Forms.Label();
            this.MustPayLabel = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.AllMoneyLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // MirevBox
            // 
            this.MirevBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.MirevBox.Font = new System.Drawing.Font("Segoe UI Semibold", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.MirevBox.ForeColor = System.Drawing.Color.WhiteSmoke;
            this.MirevBox.Location = new System.Drawing.Point(27, 44);
            this.MirevBox.Name = "MirevBox";
            this.MirevBox.Size = new System.Drawing.Size(94, 34);
            this.MirevBox.TabIndex = 0;
            this.MirevBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.MirevBox_KeyPress);
            // 
            // KosyoBox
            // 
            this.KosyoBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.KosyoBox.Font = new System.Drawing.Font("Segoe UI Semibold", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.KosyoBox.ForeColor = System.Drawing.Color.WhiteSmoke;
            this.KosyoBox.Location = new System.Drawing.Point(300, 44);
            this.KosyoBox.Name = "KosyoBox";
            this.KosyoBox.Size = new System.Drawing.Size(100, 34);
            this.KosyoBox.TabIndex = 1;
            this.KosyoBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.KosyoBox_KeyPress);
            // 
            // Calculate
            // 
            this.Calculate.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Calculate.Font = new System.Drawing.Font("Segoe UI", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Calculate.ForeColor = System.Drawing.SystemColors.ControlLight;
            this.Calculate.Location = new System.Drawing.Point(27, 127);
            this.Calculate.Name = "Calculate";
            this.Calculate.Size = new System.Drawing.Size(162, 45);
            this.Calculate.TabIndex = 4;
            this.Calculate.Text = "Calculate";
            this.Calculate.UseVisualStyleBackColor = true;
            this.Calculate.Click += new System.EventHandler(this.Calculate_Click);
            // 
            // MirevLabel
            // 
            this.MirevLabel.AutoSize = true;
            this.MirevLabel.Font = new System.Drawing.Font("Segoe UI", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.MirevLabel.ForeColor = System.Drawing.Color.WhiteSmoke;
            this.MirevLabel.Location = new System.Drawing.Point(22, 11);
            this.MirevLabel.Name = "MirevLabel";
            this.MirevLabel.Size = new System.Drawing.Size(69, 30);
            this.MirevLabel.TabIndex = 5;
            this.MirevLabel.Text = "Mirev";
            // 
            // KoseLabel
            // 
            this.KoseLabel.AutoSize = true;
            this.KoseLabel.Font = new System.Drawing.Font("Segoe UI", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.KoseLabel.ForeColor = System.Drawing.Color.WhiteSmoke;
            this.KoseLabel.Location = new System.Drawing.Point(295, 11);
            this.KoseLabel.Name = "KoseLabel";
            this.KoseLabel.Size = new System.Drawing.Size(188, 30);
            this.KoseLabel.TabIndex = 6;
            this.KoseLabel.Text = "Hypotetical Mirev";
            this.KoseLabel.Click += new System.EventHandler(this.KoseLabel_Click);
            // 
            // DifferenceLabel
            // 
            this.DifferenceLabel.AutoSize = true;
            this.DifferenceLabel.Font = new System.Drawing.Font("Segoe UI", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.DifferenceLabel.ForeColor = System.Drawing.SystemColors.AppWorkspace;
            this.DifferenceLabel.Location = new System.Drawing.Point(392, 125);
            this.DifferenceLabel.Name = "DifferenceLabel";
            this.DifferenceLabel.Size = new System.Drawing.Size(28, 32);
            this.DifferenceLabel.TabIndex = 7;
            this.DifferenceLabel.Text = "0";
            // 
            // MustPayLabel
            // 
            this.MustPayLabel.AutoSize = true;
            this.MustPayLabel.Font = new System.Drawing.Font("Segoe UI", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.MustPayLabel.ForeColor = System.Drawing.SystemColors.AppWorkspace;
            this.MustPayLabel.Location = new System.Drawing.Point(392, 166);
            this.MustPayLabel.Name = "MustPayLabel";
            this.MustPayLabel.Size = new System.Drawing.Size(28, 32);
            this.MustPayLabel.TabIndex = 8;
            this.MustPayLabel.Text = "0";
            this.MustPayLabel.Click += new System.EventHandler(this.MustPayLabel_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Segoe UI Semibold", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.ForeColor = System.Drawing.SystemColors.AppWorkspace;
            this.label1.Location = new System.Drawing.Point(272, 127);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(110, 30);
            this.label1.TabIndex = 9;
            this.label1.Text = "Difference";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Segoe UI Semibold", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.ForeColor = System.Drawing.SystemColors.AppWorkspace;
            this.label2.Location = new System.Drawing.Point(272, 172);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(121, 25);
            this.label2.TabIndex = 10;
            this.label2.Text = "MoneyToPay";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(7, 202);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(188, 13);
            this.label3.TabIndex = 11;
            this.label3.Text = "Overall money given since 22.11.2017";
            // 
            // AllMoneyLabel
            // 
            this.AllMoneyLabel.AutoSize = true;
            this.AllMoneyLabel.Location = new System.Drawing.Point(209, 202);
            this.AllMoneyLabel.Name = "AllMoneyLabel";
            this.AllMoneyLabel.Size = new System.Drawing.Size(13, 13);
            this.AllMoneyLabel.TabIndex = 12;
            this.AllMoneyLabel.Text = "0";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.ClientSize = new System.Drawing.Size(507, 221);
            this.Controls.Add(this.AllMoneyLabel);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.MustPayLabel);
            this.Controls.Add(this.DifferenceLabel);
            this.Controls.Add(this.KoseLabel);
            this.Controls.Add(this.MirevLabel);
            this.Controls.Add(this.Calculate);
            this.Controls.Add(this.KosyoBox);
            this.Controls.Add(this.MirevBox);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Opacity = 0.94D;
            this.Text = "MyBalance";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox MirevBox;
        private System.Windows.Forms.MaskedTextBox KosyoBox;
        private System.Windows.Forms.Button Calculate;
        private System.Windows.Forms.Label MirevLabel;
        private System.Windows.Forms.Label KoseLabel;
        private System.Windows.Forms.Label DifferenceLabel;
        private System.Windows.Forms.Label MustPayLabel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label AllMoneyLabel;
    }
}


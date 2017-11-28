namespace MyBalanceAuto
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
            this.AddMoneyTextBox = new System.Windows.Forms.TextBox();
            this.AddMoney = new System.Windows.Forms.Button();
            this.HypoteticalMoneyLabel = new System.Windows.Forms.Label();
            this.MoneyDifferenceLabel = new System.Windows.Forms.Label();
            this.MirevLabel = new System.Windows.Forms.Label();
            this.SinceLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // AddMoneyTextBox
            // 
            this.AddMoneyTextBox.BackColor = System.Drawing.Color.DimGray;
            this.AddMoneyTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AddMoneyTextBox.ForeColor = System.Drawing.Color.WhiteSmoke;
            this.AddMoneyTextBox.Location = new System.Drawing.Point(53, 93);
            this.AddMoneyTextBox.Name = "AddMoneyTextBox";
            this.AddMoneyTextBox.Size = new System.Drawing.Size(100, 38);
            this.AddMoneyTextBox.TabIndex = 0;
            this.AddMoneyTextBox.Text = "0";
            // 
            // AddMoney
            // 
            this.AddMoney.DialogResult = System.Windows.Forms.DialogResult.Yes;
            this.AddMoney.Font = new System.Drawing.Font("Palatino Linotype", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AddMoney.ForeColor = System.Drawing.Color.Black;
            this.AddMoney.Location = new System.Drawing.Point(53, 186);
            this.AddMoney.Name = "AddMoney";
            this.AddMoney.Size = new System.Drawing.Size(152, 48);
            this.AddMoney.TabIndex = 1;
            this.AddMoney.Text = "AddCash";
            this.AddMoney.UseCompatibleTextRendering = true;
            this.AddMoney.UseVisualStyleBackColor = true;
            this.AddMoney.Click += new System.EventHandler(this.AddMoney_Click);
            // 
            // HypoteticalMoneyLabel
            // 
            this.HypoteticalMoneyLabel.AutoSize = true;
            this.HypoteticalMoneyLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.HypoteticalMoneyLabel.Location = new System.Drawing.Point(338, 58);
            this.HypoteticalMoneyLabel.Name = "HypoteticalMoneyLabel";
            this.HypoteticalMoneyLabel.Size = new System.Drawing.Size(313, 32);
            this.HypoteticalMoneyLabel.TabIndex = 2;
            this.HypoteticalMoneyLabel.Text = "HypoteticalMoneyLabel";
            // 
            // MoneyDifferenceLabel
            // 
            this.MoneyDifferenceLabel.AutoSize = true;
            this.MoneyDifferenceLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MoneyDifferenceLabel.Location = new System.Drawing.Point(338, 99);
            this.MoneyDifferenceLabel.Name = "MoneyDifferenceLabel";
            this.MoneyDifferenceLabel.Size = new System.Drawing.Size(54, 32);
            this.MoneyDifferenceLabel.TabIndex = 3;
            this.MoneyDifferenceLabel.Text = "diff";
            // 
            // MirevLabel
            // 
            this.MirevLabel.AutoSize = true;
            this.MirevLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MirevLabel.Location = new System.Drawing.Point(50, 58);
            this.MirevLabel.Name = "MirevLabel";
            this.MirevLabel.Size = new System.Drawing.Size(155, 32);
            this.MirevLabel.TabIndex = 4;
            this.MirevLabel.Text = "MirevLabel";
            // 
            // SinceLabel
            // 
            this.SinceLabel.AutoSize = true;
            this.SinceLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SinceLabel.Location = new System.Drawing.Point(464, 247);
            this.SinceLabel.Name = "SinceLabel";
            this.SinceLabel.Size = new System.Drawing.Size(46, 18);
            this.SinceLabel.TabIndex = 5;
            this.SinceLabel.Text = "label1";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DimGray;
            this.ClientSize = new System.Drawing.Size(698, 288);
            this.Controls.Add(this.SinceLabel);
            this.Controls.Add(this.MirevLabel);
            this.Controls.Add(this.MoneyDifferenceLabel);
            this.Controls.Add(this.HypoteticalMoneyLabel);
            this.Controls.Add(this.AddMoney);
            this.Controls.Add(this.AddMoneyTextBox);
            this.ForeColor = System.Drawing.Color.WhiteSmoke;
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox AddMoneyTextBox;
        private System.Windows.Forms.Button AddMoney;
        private System.Windows.Forms.Label HypoteticalMoneyLabel;
        private System.Windows.Forms.Label MoneyDifferenceLabel;
        private System.Windows.Forms.Label MirevLabel;
        private System.Windows.Forms.Label SinceLabel;
    }
}


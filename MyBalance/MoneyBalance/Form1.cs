using System;
using System.Windows.Forms;
using System.IO;
using System.Linq;
using System.Drawing;


namespace MyBalance
{
    public partial class Form1 : Form
    {
        decimal mirevBalance = 0m;
        decimal kosyoBalance = 0m;
        decimal difference = 0m;
        decimal mustPay = 0m;
        decimal mirevCurrDotation = 0m;
        decimal kosyoCurrDotation = 0m;

        public Form1()
        {
            InitializeComponent();
            decimal[] balanceData;
            try
            {
                balanceData = (File.ReadAllLines("data.txt")).ToList().Select(decimal.Parse).ToArray();
            }
            catch(Exception e)
            {
                File.WriteAllLines("data.txt",new[]{"0","0"});
                balanceData = (File.ReadAllLines("data.txt")).ToList().Select(decimal.Parse).ToArray();
            }
            
           
            mirevBalance = balanceData[0];
            kosyoBalance = balanceData[1];
            RefreshIt();
        }

        private void Calculate_Click(object sender, EventArgs e)
        {
            if(decimal.TryParse(MirevBox.Text, out mirevCurrDotation))
            {
                this.mirevBalance += mirevCurrDotation;
            }
            if(decimal.TryParse(KosyoBox.Text, out kosyoCurrDotation))
            {
                this.kosyoBalance += kosyoCurrDotation;
            }
            string[] newBalance = new string[2] { mirevBalance.ToString(), kosyoBalance.ToString() };
            File.WriteAllLines("data.txt", newBalance);
            MirevBox.Text = null;
            KosyoBox.Text = null;
            RefreshIt();
        }

        private void RefreshIt()
        {
            difference = mirevBalance - kosyoBalance;
            DifferenceLabel.Text = Math.Abs(difference).ToString();
            if (difference != 0) ColorSwitch();
            else
            {
                MirevLabel.ForeColor = Color.WhiteSmoke;
                KoseLabel.ForeColor = Color.WhiteSmoke;
                MustPayLabel.Text = "0";
            }

            AllMoneyLabel.Text = (mirevBalance + kosyoBalance).ToString();
           
        }

        private void ColorSwitch()
        {
            mustPay = difference / 2;
            if ( difference < 0)
            {
                MirevLabel.ForeColor = Color.Red;
                KoseLabel.ForeColor = Color.WhiteSmoke;
            }
            else
            {
                MirevLabel.ForeColor = Color.WhiteSmoke;
                KoseLabel.ForeColor = Color.Red;
            }
            MustPayLabel.Text = Math.Abs(mustPay).ToString();
        }

        private void MustPayLabel_Click(object sender, EventArgs e)
        {

        }

        private void MirevBox_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == '\r') Calculate_Click(sender,e);
        }

        private void KosyoBox_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == '\r') Calculate_Click(sender, e);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void KoseLabel_Click(object sender, EventArgs e)
        {

        }
    }
}

using System;
using System.Drawing;
using System.Windows.Forms;
using System.IO;

namespace MyBalanceAuto
{
    public partial class Form1 : Form
    {
        public const string DEFAULT_PATH = "data.txt";
        public const double DEFAULT_MONEY_PER_DAY = 10.0;
        public DateTime FIRST_DAY = Convert.ToDateTime("22/11/2017");
        public double currentMirevBalance = 0.0;

        public IFileHandler handler = new FileHandler(DEFAULT_PATH);
        public Form1()
        {
            InitializeComponent();
            currentMirevBalance += handler.Data();
            AddMoney_Click(null,EventArgs.Empty);
            SinceLabel.Text = $"Since {FIRST_DAY.Day}/{FIRST_DAY.Month}/{FIRST_DAY.Year}";
        }

        private void AddMoney_Click(object sender, EventArgs e)
        {

            double currAdded = 0.0;
            double.TryParse(AddMoneyTextBox.Text,out currAdded);
            currentMirevBalance += currAdded;
            int daysPassed = (DateTime.Today.Date - FIRST_DAY).Days+1;
            double hypoteticalExpences = DEFAULT_MONEY_PER_DAY * daysPassed;
            HypoteticalMoneyLabel.Text = hypoteticalExpences.ToString();
            RealMoneyLabel.Text = currentMirevBalance.ToString();
            bool isMirevInDebt = false;
            if (hypoteticalExpences < currentMirevBalance) isMirevInDebt = true;
            MoneyDifferenceLabel.Text = Math.Abs(hypoteticalExpences - currentMirevBalance).ToString();

            if (isMirevInDebt)
            {
                MirevLabel.ForeColor = Color.Red;
                HypoteticalExp.ForeColor = Color.WhiteSmoke;
            }
            else
            {
                HypoteticalExp.ForeColor = Color.Red;
                MirevLabel.ForeColor = Color.WhiteSmoke;
            }
            handler.SaveIt(currentMirevBalance);

            AddMoneyTextBox.Text = "";
        }

        private void AddMoneyTextBox_KeyPress(object sender, KeyPressEventArgs e)
        {
            if(e.KeyChar == (char)Keys.Enter)
            {
                AddMoney_Click(null, EventArgs.Empty);
            }
        }

        private void RealMoneyLabel_Click(object sender, EventArgs e)
        {

        }
    }
}

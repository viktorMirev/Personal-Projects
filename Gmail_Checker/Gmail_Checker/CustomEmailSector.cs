using System;
using System.Windows.Forms;
using Gmail_Checker.Classes;

namespace Gmail_Checker
{
    public partial class CustomEmailSector : UserControl
    {
        public CustomEmailSector()
        {
            InitializeComponent();
        }

        private void Button_ShowFullMsg_Click(object sender, EventArgs e)
        {
            FullTextMessageForm fullMessageForm = new FullTextMessageForm();
            fullMessageForm.LoadFullMessageData(this.content,this.sender,this.subject);
            fullMessageForm.ShowDialog();
            
        }
    }
}

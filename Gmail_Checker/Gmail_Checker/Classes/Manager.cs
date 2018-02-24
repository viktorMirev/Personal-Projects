using Gmail_Checker.Interfaces;
using System.Collections.Generic;
using System.Text;

namespace Gmail_Checker.Classes
{
    public class Manager : IManager
    {
        private IDictionary<string,ICustomMessage> currentMessages;
        private IGmailHandler gmail;
        public Manager()
        {
            this.currentMessages = new Dictionary<string,ICustomMessage>();
            this.gmail = new GmailHandler();
        }
        public void Start(int seconds)
        {
            while (true)
            {
                var unreadMessages = gmail.ListUnreadMessages();
                if (!Compare(unreadMessages))
                {
                    MessageForm1 currForm = new MessageForm1();
                    currForm.LoadSectors(currentMessages);
                    currForm.ShowDialog();
                    System.Threading.Thread.Sleep(seconds * 1000);
                }
            }
          
        }

        private bool Compare(IList<string> unrList)
        {
            foreach (var msg in unrList)
            {
                if (!this.currentMessages.ContainsKey(msg))
                {
                    this.currentMessages = gmail.GetUnreadMessages();
                    return false;
                }
            }
            return true;
        }
    }
}

using Gmail_Checker.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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
            gmail.Init();
        }
        private string ListThem()
        {
            StringBuilder result = new StringBuilder("");
            foreach (var msg in currentMessages)
            {
                result.AppendLine(msg.Key);
                result.AppendLine(msg.Value.Snippet);
                result.AppendLine();
            }
            return result.ToString();
        }
        public void Start(int seconds)
        {
            while (true)
            {
                var unreadMessages = gmail.LoadUnreadMesseges();
                if (!Compare(unreadMessages))
                {
                    MessageForm1 f = new MessageForm1();
                    f.Box.Text = ListThem();
                    f.ShowDialog();
                    System.Threading.Thread.Sleep(seconds * 1000);
                }
            }
          
        }

        private bool Compare(IDictionary<string, ICustomMessage> dict)
        {
            foreach (var msg in dict)
            {
                if (!this.currentMessages.ContainsKey(msg.Key))
                {
                    this.currentMessages = dict;
                    return false;
                }
            }
            return true;
        }
    }
}

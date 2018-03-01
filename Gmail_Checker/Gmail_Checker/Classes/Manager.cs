using Gmail_Checker.Interfaces;
using System.Collections.Generic;

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
                if (!CompareN_Clean(unreadMessages))
                {
                    MessageForm1 currForm = new MessageForm1();
                    currForm.LoadSectors(currentMessages);
                    currForm.ShowDialog();
                    System.Threading.Thread.Sleep(seconds * 1000);
                }
            }
          
        }

        private bool CompareN_Clean(IList<string> unrList)
        {
            foreach (var msg in unrList)
            {
                if(!currentMessages.ContainsKey(msg))
                {
                    currentMessages = gmail.GetUnreadMessages();
                    return false;
                }
            }
            return true;
            /*
            bool areEqual = true;
            IList<bool> ToBeExcluded = new List<bool>();
            for (int i = 0; i < unrList.Count; i++)
            {
                if (this.currentMessages.ContainsKey(unrList[i]))
                {
                    ToBeExcluded.Add(true);
                }
                else
                {
                    ToBeExcluded.Add(false);
                    areEqual = false;
                }
            }

            for (int i = 0; i < ToBeExcluded.Count; i++)
            {
                if (!ToBeExcluded[i]) unrList.RemoveAt(i);
            }

            

            return areEqual;
            */
        }
    }
}

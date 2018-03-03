
using System;
using System.Collections.Generic;
using MailKit;
using MailKit.Search;
using MailKit.Security;
using MailKit.Net.Imap;
using Gmail_Checker.Interfaces;

namespace Gmail_Checker.Classes
{

    public class GmailHandler : IGmailHandler
    {
        private const int MAXIMUM_AGE_OF_MESSAGES_DAYS = 50;

        public IDictionary<string, ICustomMessage> GetUnreadMessages()
        {
            var allUnread = new Dictionary<string, ICustomMessage>();

            using (var client = new ImapClient(new ProtocolLogger("imap.log")))
            {
                client.Connect("imap.gmail.com", 993, SecureSocketOptions.SslOnConnect);

                client.Authenticate("example@gmail.com", "password");

                client.Inbox.Open(FolderAccess.ReadOnly);



                var uids = client.Inbox.Search
                    (SearchQuery.SentAfter(DateTime.Today - TimeSpan.FromDays(MAXIMUM_AGE_OF_MESSAGES_DAYS))
                    .And(SearchQuery.NotSeen).And((SearchQuery.Not((SearchQuery.HasGMailLabel("Social")).Or(SearchQuery.HasGMailLabel("Promotions"))))));


                //  int count = 0;
                for (int i = uids.Count - 1; i >= 0; i--)
                {
                    var message = client.Inbox.GetMessage(uids[i]);

                    allUnread.Add(uids[i].Id.ToString(), new CustomMessage(message));


                }


                client.Disconnect(true);
            }
            return allUnread;
        }

        public IList<string> ListUnreadMessages()
        {


            var allUnread = new List<string>();
            using (var client = new ImapClient(new ProtocolLogger("imap.log")))
            {
                client.Connect("imap.gmail.com", 993, SecureSocketOptions.SslOnConnect);

                client.Authenticate("example@gmail.com", "password");

                client.Inbox.Open(FolderAccess.ReadOnly);

                var uids = client.Inbox.Search
                    (SearchQuery.SentAfter(DateTime.Today - TimeSpan.FromDays(MAXIMUM_AGE_OF_MESSAGES_DAYS))
                    .And(SearchQuery.NotSeen).And((SearchQuery.Not((SearchQuery.HasGMailLabel("Social")).Or(SearchQuery.HasGMailLabel("Promotions"))))));


                // int count = 0;
                foreach (var uid in uids)
                {
                    allUnread.Add(uid.Id.ToString());
                    // count++;
                    //    if (count == 100) break;
                }

                client.Disconnect(true);
            }

            return allUnread;
        }
    }
}

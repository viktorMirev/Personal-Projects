
using System;
using System.Collections.Generic;

using MimeKit;
using MailKit;
using MailKit.Search;
using MailKit.Security;
using MailKit.Net.Imap;
using Gmail_Checker.Interfaces;

namespace Gmail_Checker.Classes
{
    public class GmailHandler : IGmailHandler
    {
        /*
         * create additional list with just ids unfiltered
         * then you are going to compare with it 
         * current will be filtered
         * 
         * още като се появи разлика добавяй тея дето не си ги срещнал за теглене и тия дето ги няма в новите ги трий
         * тоест връщай обект с нови и такива за триене и добавяй и трий в manager
        */
     
        public IDictionary<string,ICustomMessage> GetUnreadMessages()
        {
            var allUnread = new Dictionary<string, ICustomMessage>();

            using (var client = new ImapClient(new ProtocolLogger("imap.log")))
            {
                client.Connect("imap.gmail.com", 993, SecureSocketOptions.SslOnConnect);

                client.Authenticate("viktor.mirev@gmail.com", "paraphernalia");

                client.Inbox.Open(FolderAccess.ReadOnly);

                var uids = client.Inbox.Search(SearchQuery.NotSeen);

                int count = 0;
                foreach (var uid in uids)
                {
                    var message = client.Inbox.GetMessage(uid);

                    allUnread.Add(uid.Id.ToString(), new CustomMessage(message));

                    count++;
                    if (count == 100) { break; }
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

                client.Authenticate("viktor.mirev@gmail.com", "paraphernalia");

                client.Inbox.Open(FolderAccess.ReadOnly);

                var uids = client.Inbox.Search(SearchQuery.NotSeen);

                int count = 0;
                foreach (var uid in uids)
                {
                    allUnread.Add(uid.Id.ToString());
                    count++;
                    if (count == 100) break;
                }

                client.Disconnect(true);
            }
            return allUnread;
        }
    }
}

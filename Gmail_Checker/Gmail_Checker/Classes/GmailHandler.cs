
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
        private const int MAXIMUM_AGE_OF_MESSAGES_DAYS = 40;

        public IDictionary<string, ICustomMessage> GetUnreadMessages()
        {
            var allUnread = new Dictionary<string, ICustomMessage>();

            using (var client = new ImapClient(new ProtocolLogger("imap.log")))
            {
                client.Connect("imap.gmail.com", 993, SecureSocketOptions.SslOnConnect);

                client.Authenticate("viktor.mirev@gmail.com", "paraphernalia");

                client.Inbox.Open(FolderAccess.ReadOnly);

           
                var uids = client.Inbox.Search(SearchQuery.SentAfter(DateTime.Today - TimeSpan.FromDays(MAXIMUM_AGE_OF_MESSAGES_DAYS)).And(SearchQuery
                   .NotSeen
                    .And((SearchQuery
                    .Not
                     ((SearchQuery.HasGMailLabel("CATEGORY_SOCIAL").Or(SearchQuery.HasGMailLabel("CATEGORY_PROMOTIONS"))))))));

              //  int count = 0;
                foreach (var uid in uids)
                {
                    var message = client.Inbox.GetMessage(uid);

                    allUnread.Add(uid.Id.ToString(), new CustomMessage(message));

                   // count++;
                   // if (count == 100) { break; }
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

                var uids = client.Inbox.Search(SearchQuery.SentAfter(DateTime.Today - TimeSpan.FromDays(MAXIMUM_AGE_OF_MESSAGES_DAYS)).And(SearchQuery
                   .NotSeen
                    .And((SearchQuery
                    .Not
                     ((SearchQuery.HasGMailLabel("CATEGORY_SOCIAL").Or(SearchQuery.HasGMailLabel("CATEGORY_PROMOTIONS"))))))));

                
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

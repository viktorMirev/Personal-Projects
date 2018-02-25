using Gmail_Checker.Interfaces;
using MimeKit;
using System;

namespace Gmail_Checker.Classes
{
    public class CustomMessage : ICustomMessage

    {
        private string id;
        private string snippet;
        private string subject;
        private string sender;
        private string content;

        public string Id
        {
            get => this.id;
            private set => this.id = value;
        }

        public string Snippet
        {
            get => this.snippet;
            private set => this.snippet = value;
        }

        public string Subject
        {
            get => this.subject;
            private set => this.subject = value;
        }
        public string Sender
        {
            get => this.sender;
            private set => this.sender = value;
        }
        public string Content
        {
            get => this.content;
            private set => this.content = value;
        }

        public CustomMessage(MimeMessage msg)
        {
            this.Id = msg.MessageId;
            if(msg.TextBody.Length!=0)
            {
                int index = msg.TextBody.IndexOf('.');
                if (index < 0) index = 100;
                this.Snippet = msg.TextBody.Substring(0,Math.Min(index,msg.TextBody.Length-1));
            }
            this.Content = msg.TextBody;
            this.Sender = msg.From.ToString();
            this.Subject = msg.Subject;
        }

        public override string ToString()
        {
            return snippet;
        }
    }
}

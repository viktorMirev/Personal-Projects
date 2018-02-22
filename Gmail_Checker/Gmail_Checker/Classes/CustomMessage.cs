using Gmail_Checker.Interfaces;

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

        public CustomMessage(Google.Apis.Gmail.v1.Data.Message msg)
        {
            this.Id = msg.Id;
            this.Snippet = msg.Snippet;
            this.Content = "Content of the message";
            this.Sender = "Mr. Sender@ send.mail";
            this.Subject = "testing d system";
        }

        public override string ToString()
        {
            return snippet;
        }
    }
}

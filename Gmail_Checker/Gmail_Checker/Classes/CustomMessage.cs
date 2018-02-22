using Gmail_Checker.Interfaces;

namespace Gmail_Checker.Classes
{
    public class CustomMessage : ICustomMessage

    {
        private string id;
        private string snippet;
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


        public CustomMessage(Google.Apis.Gmail.v1.Data.Message msg)
        {
            this.Id = msg.Id;
            this.snippet = msg.Snippet;
        }

        public override string ToString()
        {
            return snippet;
        }
    }
}

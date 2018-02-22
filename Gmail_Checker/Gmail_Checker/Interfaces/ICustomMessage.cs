namespace Gmail_Checker.Interfaces
{
    public interface ICustomMessage
    {
        string Id { get; }
        string Snippet { get; }

        string Subject { get; }

        string Sender { get; }

        string Content { get; }
    }
}

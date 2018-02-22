using System.Collections.Generic;

namespace Gmail_Checker.Interfaces
{
    public interface IGmailHandler
    {
        void Init();
        IDictionary<string,ICustomMessage> LoadUnreadMesseges();
    }
}

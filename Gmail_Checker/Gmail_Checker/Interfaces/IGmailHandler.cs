using System.Collections.Generic;

namespace Gmail_Checker.Interfaces
{
    public interface IGmailHandler
    {
        void Init();
        IList<Google.Apis.Gmail.v1.Data.Message> LoadUnreadMesseges();
    }
}

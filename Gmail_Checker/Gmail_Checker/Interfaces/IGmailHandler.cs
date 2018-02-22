using System.Collections.Generic;

namespace Gmail_Checker.Interfaces
{
    public interface IGmailHandler
    {
        void Init();
        IList<ICustomMessage> LoadUnreadMesseges();
    }
}

using System.Collections.Generic;

namespace Gmail_Checker.Interfaces
{
    public interface IGmailHandler
    {
       
        IDictionary<string,ICustomMessage> GetUnreadMessages();

        IList<string> ListUnreadMessages();
    }
}

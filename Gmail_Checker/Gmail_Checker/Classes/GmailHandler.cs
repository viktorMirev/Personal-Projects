using Google.Apis.Auth.OAuth2;
using Google.Apis.Gmail.v1;
using Google.Apis.Services;
using Google.Apis.Util.Store;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading;

namespace Gmail_Checker.Classes
{
    public class GmailHandler
    {
        private string[] scopes = { GmailService.Scope.GmailReadonly };
        private string applicationName = "Gmail API .NET Quickstart";
        private UserCredential credential;
        private GmailService service;
        private void CredentialInit()
        {
            using (var stream = new FileStream("Gmail_JSON/client_secret.json", FileMode.Open, FileAccess.Read))
            {
                string credPath = System.Environment.GetFolderPath(
                    System.Environment.SpecialFolder.Personal);
                credPath = Path.Combine(credPath, ".credentials/gmail-dotnet-quickstart.json");

                credential = GoogleWebAuthorizationBroker.AuthorizeAsync(
                    GoogleClientSecrets.Load(stream).Secrets,
                    scopes,
                    "user",
                    CancellationToken.None,
                    new FileDataStore(credPath, true)).Result;
                //Console.WriteLine("Credential file saved to: " + credPath);
            }
        }
        private void ServiseInit()
        {
            service = new GmailService(new BaseClientService.Initializer()
            {
                HttpClientInitializer = credential,
                ApplicationName = applicationName,
            });
        }
        public void Init()
        {
            //Initialise credential
            CredentialInit();
            // Initialise Gmail API service.
            ServiseInit();
        }

        public IList<Google.Apis.Gmail.v1.Data.Message> LoadUnreadMesseges();

        private IList<Google.Apis.Gmail.v1.Data.Message> GetUnreadMessegesIDs()
        {
            //creatingRequest
            UsersResource.MessagesResource.ListRequest request = service.Users.Messages.List("me");

            return request.Execute().Messages.Where(t => t.LabelIds.Contains("UNREAD")).ToList();
        }
         


    }

}

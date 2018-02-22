using Gmail_Checker.Interfaces;
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
    public class GmailHandler : IGmailHandler
    {
        private const int NUMBER_OF_MESSEGES_TO_CHECK = 50;

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

        public IDictionary<string,ICustomMessage> LoadUnreadMesseges()
        {
            var firstMesseges = GetMessegesIDs();
            for (int i = 0; i < firstMesseges.Count; i++)   
            {
                var reqest = service.Users.Messages.Get("me", firstMesseges[i].Id);
                firstMesseges[i] = reqest.Execute();
            }

            IDictionary<string,ICustomMessage> finalList = new Dictionary<string,ICustomMessage>();

            for (int i = 0; i < firstMesseges.Count; i++)
            {
                if((firstMesseges[i].LabelIds.Contains("UNREAD") &&
                    (!firstMesseges[i].LabelIds.Contains("CATEGORY_PROMOTIONS") && 
                    !firstMesseges[i].LabelIds.Contains("CATEGORY_SOCIAL"))))
                {
                    finalList.Add(firstMesseges[i].Id, new CustomMessage(firstMesseges[i]));
                }
            }

            return finalList;
        }

        private IList<Google.Apis.Gmail.v1.Data.Message> GetMessegesIDs()
        {
            //creatingRequest
            UsersResource.MessagesResource.ListRequest request = service.Users.Messages.List("me");

            return request
                .Execute().Messages
                .Take(NUMBER_OF_MESSEGES_TO_CHECK)
                .ToList();
        }
    }
}

using Gmail_Checker.Classes;
using Gmail_Checker.Interfaces;
using System;

public class Program
{
    static void Main()
    {
        IGmailHandler test = new GmailHandler();
        test.Init();

        var testList = test.LoadUnreadMesseges();
        int count = 0;
        foreach (var msg in testList)
        {
            Console.WriteLine(++count);
            Console.WriteLine(msg.Id);
            Console.WriteLine(msg.Snippet);
        }
        Console.Read();
    }
}


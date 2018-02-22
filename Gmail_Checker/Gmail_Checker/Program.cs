using Gmail_Checker.Classes;
using Gmail_Checker.Interfaces;
using System;

public class Program
{
    static void Main()
    {
        IManager manager = new Manager();
        manager.Start(20);
        Console.Read();
    }
}


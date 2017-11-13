using System;
using System.IO;

//Program which assembles the splitted files into one again
//Last edit 01.11.17 (User friendly interface added)
//Viktor Mirev

namespace FileConjunction
{

    public class Program
    {
        static void Main(string[] args)
        {
            //interface
            Console.WriteLine("----------------------------------------                                          ____________________");
            Console.WriteLine("---------FILE ASSEMBLING SYSTEM---------                                          Author: Viktor Mirev");
            Console.WriteLine("----------------------------------------                                          Version: 2.3" + Environment.NewLine);


            Console.Write("Please enter the location of the files: ");
            string filesPath = Console.ReadLine();
            Console.WriteLine();

            //in case of noob users
            while (Directory.Exists(filesPath) == false)
            {
                Console.WriteLine("....................................");
                Console.WriteLine("Error! The directory does not exist!");
                Console.Write("Try again: ");
                filesPath = Console.ReadLine();
                Console.WriteLine();
            }


            //reading the data.txt to get the: 
            //extention
            //name
            //extention
            // of the file
            var data = File.ReadAllLines(filesPath + "\\data.txt");

            string nameOfFile = data[0];

            int numberOfFiles = int.Parse(data[1]);

            //method to assemble files
            ConjucntFiles(nameOfFile, numberOfFiles, filesPath);
        }

        private static void ConjucntFiles(string nameOfFile, int numberOfFiles, string path)
        {
            int chunkIndex = 0;
            //open the file to assemble
            Console.WriteLine("Assembling Progress:" + Environment.NewLine);



            //stream for the assembled file
            using (Stream output = File.OpenWrite(path + nameOfFile))
            {
                //the size of the chunks which fill the buffer
                int readSize = 10;
                readSize <<= 10;

                //the size of the buffer
                int bufferSize = 10;
                bufferSize <<= 20;

                byte[] buffer = new byte[bufferSize];

                //loop to open all files
                while (chunkIndex < numberOfFiles)
                {

                    //Filestream for each of the chunks
                    using (Stream input = File.OpenRead(path + "\\filePart" + chunkIndex.ToString()))
                    {
                        Console.WriteLine("System reading file {0} of {1}...", chunkIndex + 1, numberOfFiles);

                        //reading the current chunk until it is all read
                        while (input.Position < input.Length)
                        {
                            int bytesRead = 0;

                            //filling the buffer
                            while (bytesRead < bufferSize && input.Position < input.Length)
                            {
                                bytesRead += input.Read(buffer, bytesRead, Math.Min(readSize, buffer.Length - bytesRead));
                                //report for the progress of each file
                                Console.Write($"\r{(long)input.Position * 100 / input.Length}%");
                            }

                            //writing in the assembled file. The stream saves the last position
                            output.Write(buffer, 0, bytesRead);
                        }
                        Console.Write("\rDone...");
                        Console.WriteLine();
                    }
                    chunkIndex++;
                }
            }
            Console.WriteLine(Environment.NewLine + "Assembly successful!" + Environment.NewLine);
            Console.Write("Press any key to continue...");
            Console.ReadLine();
        }
    }
}

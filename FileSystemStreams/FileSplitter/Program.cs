using System;
using System.IO;

//Program which splits a file into smaller chunks 

//Last edit 01.11.17 
//(User friendly interface added && 
//bug with the data.txt fixed(it is not saved until you press any ey to continue) 

//Viktor Mirev

namespace FileSplitter
{
    public class Program
    {
        static void Main(string[] args)
        {
            //interface 
            Console.WriteLine("-----------------------------------                                         ____________________");
            Console.WriteLine("-------FILE SPLITTING SYSTEM-------                                         Author: Viktor Mirev");
            Console.WriteLine("-----------------------------------                                         Version: 2.4" + Environment.NewLine);
            Console.Write("Please enter the path of the file: ");

            string filePath = Console.ReadLine();
            Console.WriteLine();

            //in case of noob users
            while (File.Exists(filePath) == false)
            {
                Console.WriteLine("...............................");
                Console.WriteLine("Error! The file does not exist!");
                Console.Write("Try again: ");
                filePath = Console.ReadLine();
                Console.WriteLine();
            }

            Console.Write("Please enter the size of a part[MB]: ");


            int size = int.Parse(Console.ReadLine());

            Console.WriteLine();

            int numberOfParts = SplitFile(filePath, size);

            string fileName = filePath.Substring(filePath.LastIndexOf("\\"));

            //creating an array with the data of the file 
            //name
            //extention
            //number of parts
            var data = new string[2];
            data[0] = fileName;
            data[1] = (numberOfParts).ToString();
            
            //creating a file with the information in data[int]
            File.AppendAllLines(filePath.Remove(filePath.LastIndexOf("\\")) + "\\FileParts\\data.txt", data);

            Console.Write("Press any key to continue...");
            Console.ReadLine();
        }

        private static int SplitFile(string filePath, int size)
        {

            //getting the path to the folder without the name of the file
            string folderOfFile = filePath.Remove(filePath.LastIndexOf("\\"));

            //creating folder for the parts
            Directory.CreateDirectory(folderOfFile + "\\FileParts");

            //the size of the whole chunk 
            long allSize;

            //check if the chunk size is greather than 1GB if so the buffer is one GB 
            // else the buffer has the size of the chunk
            //if the size of the buffer is more than 1GB there si going to be a problem 
            //with the RAM

            if (size > 1024)
            {
                allSize = size;
                allSize <<= 20;
                size = 1024;
                size <<= 20;
            }
            else
            {
                size <<= 20;
                allSize = size;
            }

            //set the size in GB


            //buffer which is filled with 10kb chunks
            byte[] buffer = new byte[size];
            int readSize = 10;


            //setting the size which is filling the buffer step by step (also the minimum buffer size)
            readSize <<= 10;

            int chunkIndex = 0;

            Console.WriteLine("Splitting Progress:" + Environment.NewLine);
            //open file for reading
            using (Stream input = File.OpenRead(filePath))
            {

                //for the whole input file
                while (input.Position < input.Length)
                {
                    Console.WriteLine("System creating file {0}...", chunkIndex);

                    //the bytes already in the chunk
                    long allBytesRead = 0;

                    //stream for the current chunk
                    using (Stream output = File.OpenWrite(folderOfFile + "\\FileParts\\filePart" + chunkIndex.ToString()))
                    {
                        //loop for the whole chunk (it ends when the whole file is read of the whole chunk
                        // size is filled)
                        while (input.Position < input.Length && allBytesRead < allSize)
                        {
                            //the bytes already in the buffer
                            int bufferBytesRead = 0;

                            //filling the buffer
                            while (bufferBytesRead < size && input.Position < input.Length)
                            {
                                //the amount of bytes read at the current itteration
                                int currRead = 0;
                                currRead += input
                                    .Read(buffer, bufferBytesRead, Math.Min(readSize, buffer.Length - bufferBytesRead));
                                bufferBytesRead += currRead;
                                allBytesRead += currRead;

                                //report about the progress of the current chunk
                                //may be less or more than 100% if the size is NOT proportional of 1GB && > 1GB
                                Console.Write($"\r{(long)allBytesRead * 100 / allSize}%");
                            }

                            //writes the buffer in the chunk file (multiple times)
                            output.Write(buffer, 0, bufferBytesRead);
                        }
                        Console.Write("\rDone...");
                        Console.WriteLine();
                    }
                    chunkIndex++;
                }
            }
            Console.WriteLine(Environment.NewLine + "Split successful!" + Environment.NewLine);
            return chunkIndex;
        }
    }
}

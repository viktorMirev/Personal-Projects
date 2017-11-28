using System.IO;

public class FileHandler : IFileHandler
{
    private string filePath;
    public string FilePath
    {
        get
        {
            return filePath;
        }
        private set
        {
            if (File.Exists(FilePath) == true) this.filePath = FilePath;
            else File.WriteAllLines("data.txt", new string[] { "0" });


            this.filePath = "data.txt";
        }
    }

    public FileHandler(string path)
    {
        this.FilePath = path;
    }

    public double Data()
    {
        return double.Parse(File.ReadAllLines(this.filePath)[0]);
    }

    public void SaveIt(double newData)
    {
        File.WriteAllLines(this.filePath, new string[] { newData.ToString() });
    }
}


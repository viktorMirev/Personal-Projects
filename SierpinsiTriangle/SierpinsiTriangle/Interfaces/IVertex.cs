namespace SierpinsiTriangle.Interfaces
{
    public interface IVertex
    {
        int X { get; set; }
        int Y { get; set; }

        IVertex MiddleVertex(IVertex first);
    }
}

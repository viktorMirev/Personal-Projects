using System;
using SierpinsiTriangle.Interfaces;

namespace SierpinsiTriangle.Models
{
    public class Vertex : IVertex
    {
        private int x;
        private int y;

        public int Y { get => y; set => y = value; }
        public int X { get => x; set => x = value; }

        public Vertex(int x,int y)
        {
            this.X = x;
            this.Y = y;
        }

        public IVertex MiddleVertex(IVertex first)
        {
            int newX = Math.Abs(this.x + first.X)/2;
            int newY = Math.Abs(this.y + first.Y)/2;

            return new Vertex(newX, newY);
        }
    }
}

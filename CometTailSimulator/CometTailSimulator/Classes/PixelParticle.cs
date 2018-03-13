namespace CometTailSimulator.Classes
{
    public class PixelParticle
    {
        private int x;
        private int y;
        private double size;

        PixelParticle(int x, int y, double size)
        {
            this.x = x;
            this.y = y;
            this.size = size;
        }
        public int X { get => x; set => x = value; }
        public int Y { get => y; set => y = value; }
        public double Size { get => size; set => size = value; }
    }
}

namespace CometTailSimulator.Classes
{
    public class Velocity
    {
        private double x;
        private double y;
        public Velocity(double x, double y)
        {
            this.x = x;
            this.y = y;
        }

        public Velocity Add(Velocity second)
        {
            double newX = this.x + second.x;
            double newY = this.y + second.y;

            return new Velocity(newX, newY);
        }
    }
}

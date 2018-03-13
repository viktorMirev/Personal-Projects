namespace CometTailSimulator.Classes
{
    abstract class Constants
    {
        public static readonly int centralMassX = 0;       //the x coordinate of the sun
        public static readonly int centralMassY = 0;       //the y coordinate of the sun
        public static readonly double c = 300000000;       //the speed of light
        public static readonly double L = 2 * (10e30);     //the luminosity of the sun
        public static readonly double AU = 149600000000;   //the distance between The Earth & the sun
        public static readonly double A = 0.5;             //the AVG albedo of the particles
        public static readonly double p = 1.5;             //the AVG density of the particles
        public static readonly double dayInS = 86400;      //the number of seconds in a day
        public static readonly int scale = 15000000;       //meters per pixl
        public static readonly double micron = 1 * (10e-6);//micron

    }
}

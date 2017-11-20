using SierpinsiTriangle.Interfaces;
using SierpinsiTriangle.Models;
using System;
using System.Drawing;
using System.Windows.Forms;

namespace SierpinsiTriangle
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
               
        }

        private void PictureBox1_Click(object sender, EventArgs e)
        {

        }
        
       


        private void Button1_Click(object sender, EventArgs e)
        {
            var currColor = Color.FromArgb(193, 169, 7);
            Bitmap currImg = new Bitmap(1366, 768);
            this.pictureBox1.Size = new Size(1366, 768);
            this.pictureBox1.BackColor = Color.Black;
            int steps = 0;
            int topPadding = 0;
            int leftNRightPadding = 0;
            int tilt = 0;
            if(textBoxTilt.Text!="" && textBoxTilt.Text != null)
            {
                tilt = int.Parse(textBoxTilt.Text);
            }
            try
            {
                steps = int.Parse(this.TextBoxSteps.Text);
                topPadding = int.Parse(this.textBoxTop.Text);
                leftNRightPadding = int.Parse(this.textBoxLeftNRight.Text);
            }
            catch 
            {
                MessageBox.Show("Enter a valid value");
            }
            

            IVertex[] corners = new IVertex[3];

            CalculateCorners(corners, topPadding,leftNRightPadding,  currImg.Height, currImg.Width, tilt);
            DrawCorners(corners, currImg, currColor);

            IVertex currVertex = new Vertex(currImg.Width/2, currImg.Height/2);

            Random myRand = new Random();

            for (int i = 0; i < steps; i++)
            {
                int currCorner = myRand.Next()%3;
                DrawVertex(currVertex, currImg,currColor);
                currVertex = corners[currCorner].MiddleVertex(currVertex);

            }
            this.pictureBox1.Image = currImg;
            //MessageBox.Show(DateTime.Now.ToFileTime().ToString());
            currImg.Save("Skirp" + DateTime.Now.ToFileTime() + ".jpg");
           
        }

        private void DrawVertex(IVertex currVertex, Bitmap currImg, Color currColor)
        {
            currImg.SetPixel(currVertex.X, currVertex.Y,  currColor);
        }

        private void CalculateCorners(IVertex[] corners, int top, int leftAndRight,int height, int width,int tilt)
        {
            corners[0] = new Vertex(leftAndRight+tilt, top);
            corners[1] = new Vertex(width-leftAndRight+tilt, top);
            corners[2] = new Vertex((width)/2-tilt, height-top);
        }

        private void DrawCorners(IVertex[] corners, Bitmap currImg, Color currColor)
        {
            foreach (var corner in corners)
            {
                currImg.SetPixel(corner.X, corner.Y, currColor);
            }

        }

        private void TextBoxSteps_TextChanged(object sender, EventArgs e)
        {

        }

        private void TextBoxSteps_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (Convert.ToInt32(e.KeyChar) == 13)
            {
                this.Button1_Click(sender,e);
            }
        }

        private void TextBoxTop_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (Convert.ToInt32(e.KeyChar) == 13)
            {
                this.Button1_Click(sender, e);
            }
        }

        private void textBoxLeftNRight_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (Convert.ToInt32(e.KeyChar) == 13)
            {
                this.Button1_Click(sender, e);
            }
        }

        private void textBoxTilt_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBoxTilt_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (Convert.ToInt32(e.KeyChar) == 13)
            {
                this.Button1_Click(sender, e);
            }
        }
    }
}

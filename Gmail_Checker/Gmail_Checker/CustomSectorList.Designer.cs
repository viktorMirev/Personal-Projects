using Gmail_Checker.Interfaces;
using System.Collections.Generic;
using System.Drawing;

namespace Gmail_Checker
{
    partial class CustomSectorList
    {
        private const int ITEM_HEIGHT = 92;
        private const int SPACING = 15;
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }
        //NEW
        public void AddMyControls(IDictionary<string, ICustomMessage> list)
        {
            int i = 0;
            //adding the custom sectors
            foreach (var msg in list)
            {
                CustomEmailSector currSector = new CustomEmailSector();

                //to be modified for all labels
                currSector.FillMessageData(msg.Value);

                currSector.Location = new Point(SPACING, SPACING + ITEM_HEIGHT * i);
                Controls.Add(currSector);
                i++;
            }
        }
        //NEW


        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.SuspendLayout();
            // 
            // CustomSectorList
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.Name = "CustomSectorList";
            this.Size = new System.Drawing.Size(818, 445);
            this.ResumeLayout(false);

        }

        #endregion
    }
}

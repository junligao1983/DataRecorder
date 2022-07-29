using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Media.Imaging;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        PictureBox pictureBox1 = new PictureBox();
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            unsafe
            {
                short[] shorts = new short[] { 1, 2 };
                IntPtr ptr = Marshal.AllocHGlobal(4);
                Marshal.Copy(shorts, 0, ptr, shorts.Length);
                uct* sptr = (uct*)ptr;
                for (int i = 0; i < 2; i++)
                {
                    Console.WriteLine(sptr->a.ToString ());
                }
            }
        }

        public struct uct
        {
            public short a;
        }
    }
}
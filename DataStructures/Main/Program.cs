using System;

using Node;

namespace Main
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write($"Assembly Runtime: {typeof(string).Assembly.ImageRuntimeVersion}\n");
            /*NodeMain.Constructor();
            TreeNodeMain.Constructor();
            MatrixMain.All();*/
            Board.Constructor();
        }
    }
}

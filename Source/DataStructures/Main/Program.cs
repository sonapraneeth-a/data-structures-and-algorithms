using System;

using DS.Node;

namespace DS.Main
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

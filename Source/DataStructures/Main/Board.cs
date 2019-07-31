using System;
using System.Collections.Generic;
using System.Text;
using DS.Miscellaneous;

namespace DS.Main
{
    public static class Board
    {
        public static void Constructor()
        {
            Board<char> b = new Board<char>(8, 8);
            b.Fill('Q');
            Console.WriteLine($"{b}");
        }
    }
}

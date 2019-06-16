using System;
using System.Collections.Generic;
using Backtracking;

namespace MainAlgo
{
    class Program
    {
        static void Main(string[] args)
        {
            // NQueens.Solve(8);
            List<int> list = new List<int>();
            for(int index = 1; index <= 10; index++)
            {
                list.Add(index);
            }
            Subsets.Enumerate(list);
        }
    }
}

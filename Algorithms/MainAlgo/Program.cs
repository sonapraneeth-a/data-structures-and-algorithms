using System;
using System.Collections.Generic;
using Backtracking;

using Extensions;

namespace MainAlgo
{
    class Program
    {
        static void Main(string[] args)
        {
            // NQueens.Solve(8);
            /*List<int> list = new List<int>();
            for(int index = 1; index <= 3; index++)
            {
                list.Add(index);
            }
            Subsets.Enumerate(list);*/
            List<int> list = new List<int>();
            list.Add(2);  list.Add(2); list.Add(4); list.Add(6); list.Add(8);
            CombinationalSum.Debug = false;
            CombinationalSum.Enumerate(list, 60);
        }
    }
}

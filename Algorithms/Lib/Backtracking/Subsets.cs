using System;
using System.Collections.Generic;
using System.Text;
using Extensions;

namespace Backtracking
{
    public static class Subsets
    {
        public static bool Debug { get; set; } = false;
        public static void Enumerate<T>(List<T> list)
        {
            List<T> currentSubset = new List<T>();
            int call = 0;
            EnumerateHelper(list, currentSubset, call);
        }
        private static void EnumerateHelper<T>(List<T> list, List<T> currentSubset, int call)
        {
            string tab = new string('\t', call);
            if(Debug) Console.WriteLine($"{tab} {call} -- Function started with {list.StringRepresentation()} with {currentSubset.StringRepresentation()}");
            if (list.Count == 0)
            {
                if (Debug) Console.Write($"{tab} (P) Solution: ");
                Console.WriteLine($"{currentSubset.StringRepresentation()}");
                return;
            }
            List<T> _list = new List<T>(list);
            T value = _list[0];
            currentSubset.Add(value);
            _list.RemoveAt(0);
            if (Debug) Console.WriteLine($"{tab} (left) Recursive call on {_list.StringRepresentation()} with {currentSubset.StringRepresentation()}");
            EnumerateHelper(_list, currentSubset, call+1);
            if (Debug) Console.WriteLine($"{tab} (after left) List: {_list.StringRepresentation()}, Current subset: {currentSubset.StringRepresentation()}");
            currentSubset.RemoveAt(currentSubset.Count - 1);
            if (Debug) Console.WriteLine($"{tab} (right) Recursive call on {_list.StringRepresentation()} with {currentSubset.StringRepresentation()}");
            EnumerateHelper(_list, currentSubset, call+2);
        }
    }
}

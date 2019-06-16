using System;
using System.Collections.Generic;
using System.Text;

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
        public static string Print<T>(List<T> list)
        {
            string rep = "[ ";
            for (int index = 0; index < list.Count; index++)
            {
                rep += $"{list[index]} ";
            }
            rep += "]";
            return rep;
        }
        private static void EnumerateHelper<T>(List<T> list, List<T> currentSubset, int call)
        {
            string tab = new string('\t', call);
            if(Debug) Console.WriteLine($"{tab} {call} -- Function started with {Print(list)} with {Print(currentSubset)}");
            if (list.Count == 0)
            {
                if (Debug) Console.Write($"{tab} (P) Solution: ");
                Console.WriteLine($"{Print(currentSubset)}");
                return;
            }
            List<T> _list = new List<T>(list);
            T value = _list[0];
            currentSubset.Add(value);
            _list.RemoveAt(0);
            if (Debug) Console.WriteLine($"{tab} (left) Recursive call on {Print(_list)} with {Print(currentSubset)}");
            EnumerateHelper(_list, currentSubset, call+1);
            if (Debug) Console.WriteLine($"{tab} (after left) List: {Print(_list)}, Current subset: {Print(currentSubset)}");
            currentSubset.RemoveAt(currentSubset.Count - 1);
            if (Debug) Console.WriteLine($"{tab} (right) Recursive call on {Print(_list)} with {Print(currentSubset)}");
            EnumerateHelper(_list, currentSubset, call+2);
        }
    }
}

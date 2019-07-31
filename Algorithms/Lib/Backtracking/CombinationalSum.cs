using System;
using System.Collections.Generic;

using Extensions;

namespace Backtracking
{
    /// <summary>
    ///     <para>
    ///         Problem: Given an array of positive integers arr[] and a sum x, 
    ///         find all unique combinations in arr[] where the sum is equal to x.
    ///         The same repeated number may be chosen from arr[] unlimited 
    ///         number of times. 
    ///     </para>
    ///     <example>
    ///         Input : arr[] = 2, 4, 6, 8 ; sum = 8 <br/>
    ///         Output : [2, 2, 2, 2], [2, 2, 4], [2, 6], [4, 4], [8]
    ///     </example>
    ///     <br/>
    ///     <remark>Reference: https://www.geeksforgeeks.org/combinational-sum/</remark>
    /// </summary>
    public static class CombinationalSum
    {

        /// <summary>
        ///     This variable indicates if debug information should be printed 
        ///     or not
        /// </summary>
        public static bool Debug { get; set; } = false;

        /// <summary>
        ///     <para>
        ///         This function prints all possible subsets which when added
        ///         result in the sum
        ///     </para>
        ///     <para>
        ///         Time Complexity: O()
        ///     </para>
        /// </summary>
        /// <param name="list">List of integers from which the subsets should be selected</param>
        /// <param name="sum">Sum for which the subsets should be chosen</param>
        // TODO: Calculate the time complexity of this algorithm
        public static void Enumerate(List<int> list, int sum)
        {
            var watch = new System.Diagnostics.Stopwatch();
            watch.Start();
            // Remove duplicates from list before passing further
            list.RemoveDuplicates();
            List<int> currentSubset = new List<int>();
            // <c>recursionDepth</c> indicates the depth of recursion
            int recursionDepth = 0;
            // EnumerateHelper01(list, currentSubset, sum, recursionDepth);
            EnumerateHelper02(list, currentSubset, sum, 0, recursionDepth);
            watch.Stop();
            Console.WriteLine($"Execution Time: {watch.ElapsedMilliseconds} ms");
        }

        /// <summary>
        ///     Subsets enumerated using this function can be repeated
        /// </summary>
        /// <param name="list"></param>
        /// <param name="currentSubset"></param>
        /// <param name="sum"></param>
        /// <param name="recursionDepth"></param>
        private static void EnumerateHelper01(List<int> list, List<int> currentSubset, int sum, int recursionDepth)
        {
            string tab = new string('\t', recursionDepth);
            if (Debug) Console.WriteLine($"{tab} {recursionDepth} -- Function started with {list.StringRepresentation()} with {currentSubset.StringRepresentation()}");
            if (sum == 0)
            {
                if (Debug) Console.Write($"{tab} (P) Solution: ");
                Console.WriteLine($"{currentSubset.StringRepresentation()}");
                return;
            }
            else if (sum < 0)
            {
                if (Debug) Console.WriteLine($"{tab} (P) No solution for this subset");
                return;
            }
            for (int index = 0; index < list.Count; index++)
            {
                int value = list[index];
                currentSubset.Add(value);
                if (Debug) Console.WriteLine($"{tab} ({index}) Recursive recursionDepth on {list.StringRepresentation()} with {currentSubset.StringRepresentation()}");
                EnumerateHelper01(list, currentSubset, sum - value, recursionDepth + 1);
                currentSubset.RemoveAt(currentSubset.Count - 1);
            }
        }

        /// <summary>
        ///     Subsets enumerated using this function are unique
        /// </summary>
        /// <param name="list"></param>
        /// <param name="currentSubset"></param>
        /// <param name="sum"></param>
        /// <param name="index"></param>
        /// <param name="recursionDepth"></param>
        private static void EnumerateHelper02(List<int> list, List<int> currentSubset, int sum, int index, int recursionDepth)
        {
            string tab = new string('\t', recursionDepth);
            if (Debug) Console.WriteLine($"{tab} {recursionDepth} -- Function started with {list.StringRepresentation()} with {currentSubset.StringRepresentation()}");
            if (sum == 0)
            {
                if (Debug) Console.Write($"{tab} (P) Solution: ");
                Console.WriteLine($"{currentSubset.StringRepresentation()}");
                return;
            }
            else if (sum < 0)
            {
                if (Debug) Console.WriteLine($"{tab} (P) No solution for this subset");
                return;
            }
            for (int item_index = index; item_index < list.Count; item_index++)
            {
                int value = list[item_index];
                currentSubset.Add(value);
                if (Debug) Console.WriteLine($"{tab} ({index}) Recursive recursionDepth on {list.StringRepresentation()} with {currentSubset.StringRepresentation()}");
                EnumerateHelper02(list, currentSubset, sum - value, item_index, recursionDepth + 1);
                currentSubset.RemoveAt(currentSubset.Count - 1);
            }
        }
    }
}

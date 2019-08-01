using System.Collections.Generic;

namespace Extensions
{
    public static class ListExtension
    {
        public static string StringRepresentation<T>(this List<T> list)
        {
            string rep = "{ ";
            for (int index = 0; index < list.Count; index++)
            {
                if (index != list.Count - 1)
                    rep += $"{list[index]}, ";
                else
                    rep += $"{list[index]} ";
            }
            rep += "}";
            return rep;
        }
        public static void RemoveDuplicates<T>(this List<T> list)
        {
            Dictionary<T, int> dict = new Dictionary<T, int>();
            int index = 0;
            while (index < list.Count)
            {
                if (dict.ContainsKey(list[index]))
                {
                    list.RemoveAt(index);
                }
                else
                {
                    dict.Add(list[index], index);
                    index++;
                }
            }
            dict.Clear();
        }
    }
}

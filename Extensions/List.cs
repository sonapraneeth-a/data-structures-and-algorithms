using System;
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
    }
}

using System;

namespace Node
{
    public class ListNode<T>
    {
        public T Data { get; set; }
        public ListNode<T> Next { get; set; } = null;
        public override string ToString()
        {
            if (Next == null)
                return $"[{Data}] -> null";
            return $"[{Data}] -> {Next?.GetHashCode()}";
        }
    }
}

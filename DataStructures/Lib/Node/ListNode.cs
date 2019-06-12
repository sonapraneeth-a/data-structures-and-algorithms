namespace Node
{
    public class ListNode<T>
    {
        public T Data { get; set; }
        public ListNode<T> Next { get; set; } = null;
        public ListNode()
        {
            // Set default value in case no argument is supplied to the 
            // constructor
            Data = default;
        }
        public ListNode(T value)
        {
            Data = value;
        }
        public override string ToString()
        {
            if (Next == null)
                return $"[{Data}] -> null";
            return $"[{Data}] -> {Next?.GetHashCode()}";
        }
    }
}

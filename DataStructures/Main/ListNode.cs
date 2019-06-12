using System;

using Node;

namespace Main
{
    public static class NodeMain
    {
        public static void Constructor()
        {
            Console.WriteLine("=== Node Constructors ===");

            Console.WriteLine("--- Node Constructor(1) ---");
            ListNode<int> Node_c1_01 = new ListNode<int>();
            Console.WriteLine($"Node_c1_01 : {Node_c1_01}");

            Console.WriteLine("--- Node Constructor(2) ---");
            ListNode<int> Node_c2_02 = new ListNode<int>(10);
            Console.WriteLine($"Node_c2_02 : {Node_c2_02}");

            Console.WriteLine();
        }
    }
}

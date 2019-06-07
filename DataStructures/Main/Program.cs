using System;

using Node;

namespace Main
{
    class Program
    {
        static void Main(string[] args)
        {
            ListNode<int> Node = new ListNode<int>();
            Node.Data = 10;
            Console.WriteLine($"{Node}");
        }
    }
}

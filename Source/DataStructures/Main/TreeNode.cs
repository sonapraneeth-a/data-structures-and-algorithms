using System;

using DS.Node;

namespace DS.Main
{
    public static class TreeNodeMain
    {
        public static void Constructor()
        {
            Console.WriteLine("=== TreeNode Constructors ===");

            Console.WriteLine("--- TreeNode Constructor(1) ---");
            TreeNode<int> TNode_c1_01 = new TreeNode<int>();
            TreeNode<int> TNode_c1_02 = new TreeNode<int>();
            TreeNode<int> TNode_c1_03 = new TreeNode<int>();
            TNode_c1_01.Data = 20;
            TNode_c1_01.AddChild(TNode_c1_02);
            // TNode_c1_01.AddChild(null);
            TNode_c1_01.AddChild(TNode_c1_03);
            TNode_c1_02.Data = 30;
            Console.WriteLine($"TNode_c1_01: {TNode_c1_01}");

            Console.WriteLine("--- TreeNode Constructor(2) ---");
            TreeNode<int> TNode_c2_01 = new TreeNode<int>(10);
            TreeNode<int> TNode_c2_02 = new TreeNode<int>(20);
            TreeNode<int> TNode_c2_03 = new TreeNode<int>(30);
            TNode_c2_01.AddChild(TNode_c2_02);
            // TNode_c2_01.AddChild(null);
            TNode_c2_01.AddChild(TNode_c2_03);
            Console.WriteLine($"TNode_c2_01: {TNode_c2_01}");

            Console.WriteLine();
        }
    }
}

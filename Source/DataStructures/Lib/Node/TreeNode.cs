/**
 * File description
 *
 *        Filename: TreeNode.cs
 *      Created on: 08 June 2019
 *   Last modified: 11 June 2019
 *         Authors: sonapraneeth-a
 *         Details: Node to be used in classes related to Trees
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 08-06-2019               sonapraneeth-a      - Creation of the file
 * 11-06-2019               sonapraneeth-a      - Added comments to the code
 *                                              - Added constructor for setting Data
 */

using System.Collections.Generic;
using System.Text;

namespace DS.Node
{
    /// <summary>
    /// Node class for <c>Tree</c> related classes
    /// </summary>
    public class TreeNode<T>
    {
        /// <summary>
        /// <c>Data</c> property for the TreeNode
        /// </summary>
        public T Data { get; set; }

        /// <summary>
        /// <c>Next</c> property for the TreeNode. This property contains information about
        /// children of <c>TreeNode</c>
        /// </summary>
        public List<TreeNode<T>> Next { get; private set; } = null;

        public TreeNode()
        {
            Data = default;
        }
        public TreeNode(T value)
        {
            Data = value;
        }

        /// <summary>
        /// Adds a child to the current <c>TreeNode</c>
        ///     <param><c>child</c> - Child to be added to the node</param>
        /// </summary>
        public void AddChild(TreeNode<T> child)
        {
            if (Next == null)
            {
                Next = new List<TreeNode<T>>();
            }
            Next.Add(child);
        }

        /// <summary>
        /// Return the string representation of <c>TreeNode</c>
        /// </summary>
        public override string ToString()
        {
            // String representation when the node has no children
            if (Next == null)
            {
                return $"[{Data}] -> null";
            }
            else
            {
                StringBuilder rep = new StringBuilder();
                rep.AppendLine($" + [{Data}]");
                foreach (TreeNode<T> item in Next)
                {
                    rep.AppendLine($" |-- {item.GetHashCode()} ");
                }
                return rep.ToString();
            }
        }
    }
}

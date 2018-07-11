//
// Created by pranas on 3/20/2018.
//

#include "BinaryTree.h"

int main()
{
    std::vector<int> array({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
    BinaryTree<int> *tree = new BinaryTree<int>(array);
    tree->DrawTree();
    tree->PrintInOrderTraversal(tree->GetRoot());
    std::cout << "\n";
    std::cout << "Height of tree: " << tree->GetHeightOfTree(tree->GetRoot()) << "\n";
    std::cout << "Is 7 present? " << tree->IsPresent(7) << "\n";
    std::cout << "Is 3 present? " << tree->IsPresent(3) << "\n";
    return 0;
}

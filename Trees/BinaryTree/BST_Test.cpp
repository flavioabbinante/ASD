#include <iostream>
#include "BST.h" // o il tuo file BST

int main() {

    BST<int> tree;

    tree.insert(50);
    tree.insert(60);
    tree.insert(40);
    tree.insert(15);

    tree.inOrder(tree.getRoot());
    std::cout << std::endl;
    std::cout << tree.getMin(tree.getRoot())->val << std::endl;
    std::cout << tree.getMax(tree.getRoot())->val << std::endl;

    return 0;
}

#include <iostream>
#include "BinaryTreeArray.h"
#include "BinaryTreeList.h"

/*

                                      H
                                 /         \
                               A             C
                             /   \         /   \
                           D       L     P       S
                                 /   \
                                O     Q

*/

int main() {

    // ========================
    // ALBERO BINARIO CON ARRAY
    // ========================
    BinaryTreeArray<char> treeArray;

    // Inserimento elementi
    treeArray.insRoot('h');
    treeArray.insSx(1, 'a');
    treeArray.insDx(1, 'c');
    treeArray.insSx(2, 'd');
    treeArray.insDx(2, 'l');
    treeArray.insSx(3, 'p');
    treeArray.insDx(3, 's');
    treeArray.insSx(5, 'o');
    treeArray.insDx(5, 'q');

    std::cout << "=== Albero Array ===" << std::endl;
    std::cout << "Stampa dell'albero (ricorsiva, [val, sx, dx]):" << std::endl;
    treeArray.toString();

    std::cout << "\nVisite sull'albero array:" << std::endl;
    std::cout << "PreOrder: ";
    treeArray.preOrder(1);
    std::cout << "\nInOrder: ";
    treeArray.inOrder(1);
    std::cout << "\nPostOrder: ";
    treeArray.postOrder(1);
    std::cout << "\nValore del genitore del nodo 4: " << treeArray.read(treeArray.getParent(4)) << std::endl;

    std::cout << "\n---------------------------------\n" << std::endl;

    // ==========================
    // ALBERO BINARIO CON LISTE
    // ==========================
    BinaryTreeList<char> treeList;

    // Inserimento radice
    treeList.insRoot('h');

    // Livello 1
    auto root = treeList.getRoot();
    treeList.insSx(root, 'a');
    treeList.insDx(root, 'c');

    // Livello 2
    auto a = treeList.getSx(root);
    auto c = treeList.getDx(root);

    treeList.insSx(a, 'd');
    treeList.insDx(a, 'l');

    treeList.insSx(c, 'p');
    treeList.insDx(c, 's');

    // Livello 3
    auto l = treeList.getDx(a);
    treeList.insSx(l, 'o');
    treeList.insDx(l, 'q');

    std::cout << "=== Albero Linked List ===" << std::endl;
    std::cout << "Stampa dell'albero (ricorsiva, [val, sx, dx]):" << std::endl;
    treeList.toString();

    std::cout << "\nVisite sull'albero linked list:" << std::endl;
    std::cout << "PreOrder: ";
    treeList.preOrder(treeList.getRoot());
    std::cout << "\nInOrder: ";
    treeList.inOrder(treeList.getRoot());
    std::cout << "\nPostOrder: ";
    treeList.postOrder(treeList.getRoot());
    std::cout << "\nValore del genitore del nodo 'l': " << treeList.read(treeList.getParent(l)) << std::endl;


    std::cout << "\nBFS: " << std::endl;
    treeList.BFS(treeList.getRoot());


    return 0;
}

#include <iostream>
#include "NT_FCNS.h"

int main(){

    NaryTree_FCNS<int> nTree;

    // Livello 0 e Livello 1
    nTree.setRoot(20);
    nTree.insertChild(nTree.getRoot(), 2);
    nTree.insertChild(nTree.getRoot(), 34);
    nTree.insertChild(nTree.getRoot(), 50);
    nTree.insertChild(nTree.getRoot(), 60);
    nTree.insertChild(nTree.getRoot(), 70);

    // Figli del nodo 2
    auto due = nTree.getFirstChild(nTree.getRoot());
    nTree.insertChild(due, 15);
    nTree.insertChild(due, 20);

    // Figlio del nodo 34
    auto trentaquattro = nTree.getNextSibling(due);
    nTree.insertChild(trentaquattro, 30);

    // Figli del nodo 50
    auto cinquanta = nTree.getNextSibling(trentaquattro);
    nTree.insertChild(cinquanta, 40);
    nTree.insertChild(cinquanta, 100);
    nTree.insertChild(cinquanta, 20);

    // Figli del nodo 20 (quello sotto il 2)
    auto ventiSottoDue = nTree.getNextSibling(nTree.getFirstChild(due));
    nTree.insertChild(ventiSottoDue, 25);
    nTree.insertChild(ventiSottoDue, 50);

    // Output di verifica
    nTree.bfs(nTree.getRoot());
    std::cout << "\n\nLarghezza: " << nTree.getWidth() << std::endl;
    std::cout << "Profondita: " << nTree.getDepth(nTree.getRoot()) << std::endl;

    return 0;
}
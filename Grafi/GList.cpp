#include "GrafoMatrix.h"
#include <iostream>

int main(){

    GrafoMatrix<char, int> grafo(5);

    NodoGrafo n1(1);
    NodoGrafo n2(2);
    NodoGrafo n3(3);
    NodoGrafo n4(4);

    grafo.insertNode(n1,'A');
    grafo.insertNode(n2,'B');
    grafo.insertNode(n3,'C');
    grafo.insertNode(n4,'D');

    grafo.insertEdge(n1,n2,1);
    grafo.insertEdge(n2,n1,5);

    grafo.insertEdge(n1,n3,2);
    grafo.insertEdge(n2,n3,3);

    grafo.insertEdge(n3,n4,1);
    grafo.insertEdge(n4,n1,5);

    grafo.toString();

    return 0;
}
#include "LinkedList.h"
#include <iostream>

int main(){

    LinkedList<int> prima;

    prima.insListaOrdinata(6);
    prima.insListaOrdinata(5);
    prima.insListaOrdinata(4);

    LinkedList<int> gino;

    gino.insListaOrdinata(1);
    gino.insListaOrdinata(2);
    gino.insListaOrdinata(3);

    prima.merge(&gino).toString();


    return 0;

}
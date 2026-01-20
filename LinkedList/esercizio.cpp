// Conteggio Occorrenze (Liste)
#include <iostream>
#include "LinkedList.h"

using namespace std;

int contalista(LinkedList<int> &l, int x){
    int numeri =0;

    for(int i = 0; i<l.size(); i++){
        if( l.getAt(i) == x){
            numeri++;
        }

    }
    return numeri++;
}

int main(){
    cout << "--- Inizio Test ---" << endl;
    LinkedList<int> l1;

    l1.pushFront(10);
    l1.pushFront(5);
    l1.pushFront(25);
    l1.pushFront(5);
    l1.pushFront(3);

    cout << "Risultato conteggio occorrenze: " << contalista(l1, 5) << endl << endl;

    return 0;
}
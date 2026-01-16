/*
 * Esercizio 1: Implementazione di funzioni su una lista di interi.
 * * 1. int freq(List<int> &L, int k): 
 * Restituisce il numero di occorrenze dei multipli di k nella lista L.
 * 
 * * 2. void hist(List<int> &L): 
 * Stampa la frequenza di ogni elemento presente nella lista L.
 * 
 * * 3. void remp(List<int> &L): 
 * Rimuove dalla lista L tutti gli elementi seguiti da un numero dispari.
 * 
 * * Prevedere una funzione main che contenga una procedura di inserimento automatico 
 * e successivamente il test delle funzioni implementate.
 */

#include <iostream>
#include "LinkedList.h"
#include "../Dizionari/HashTable.h"

using namespace std;

int freq(LinkedList<int> &l, int k){

    int multipli = 0; // Contatore di multipli

    for (int i = 0; i < l.size(); i++)
    {
        if (l.getAt(i) % k == 0) 
        {
            multipli++;
        }
        
    }

    return multipli;
}

void remp(LinkedList<int> &l) {

    int i = 0;

    // faccio size - 1 perchè mi fermo al penultimmo visto che dopo l'ultimo non c'è niente
    while (i < l.size() - 1) {

        if (l.getAt(i + 1) % 2 != 0) {

            l.removeAt(i);  
            /* Dopo la rimozione NON si incrementa i:               */
            /* nella posizione i è appena finito un nuovo elemento  */
            /* e va controllato di nuovo.                           */

        } else {

            // Se il successivo è pari, l’elemento corrente non va rimosso,
            // quindi possiamo passare all’indice successivo.
            i++; 
        }
    }
}

// Stampa la frequenza di ogni elemento presente nella lista L.
void hist(LinkedList<int> &l, int size){

    HashTable<int,int> ht(size);

    int i = 0;
    int num;

    while(i < l.size()){
        num = l.getAt(i);

        if(ht.find(num) == nullptr){
            ht.insert(num, 1);
        }else{

            int newVal = ht.find(num)->value + 1;

            ht.modify(num, newVal);
        }

        i++;
    }

    ht.toString();
}



int main() {

    /* ============================================================
       ================ TEST FUNZIONE freq() ======================
       ============================================================ */

    LinkedList<int> l1;

    // Inserimento elementi della lista (in testa)
    l1.pushFront(10);
    l1.pushFront(5);
    l1.pushFront(25);
    l1.pushFront(30);
    l1.pushFront(3);

    cout << "TEST freq() su LISTA 1:" << endl;
    l1.toString();

    // Verifica dei multipli di 5 nella lista
    cout << "Multipli di 5 attesi: 4" << endl;
    cout << "Risultato funzione freq: " << freq(l1, 5) << endl << endl;



    /* ============================================================
       ================ TEST FUNZIONE remp() ======================
       ============================================================ */

    LinkedList<int> l2;

    // Inserimento elementi della lista: 1 - 2 - 3 - 4 - 5
    l2.pushFront(1);
    l2.pushBack(2);
    l2.pushBack(3);
    l2.pushBack(4);
    l2.pushBack(5);

    cout << "TEST remp() su LISTA 2:" << endl;
    l2.toString();

    // Applicazione della funzione remp
    remp(l2);

    cout << "Lista dopo l'operazione remp:" << endl;
    l2.toString();

    /* ============================================================
       ================ TEST FUNZIONE hist() ======================
       ============================================================ */

       LinkedList<int> l3;

       // Inserimento elementi della lista: 1 - 2 - 1 - 4 - 4 - 5 - 8
        l3.pushFront(1);
        l3.pushBack(2);
        l3.pushBack(1);
        l3.pushBack(4);
        l3.pushBack(4);
        l3.pushBack(5);
        l3.pushBack(8);
        
        l3.toString();
        
        cout << "HIST: \n" << endl;

        hist(l3,l3.size());


    return 0;
}

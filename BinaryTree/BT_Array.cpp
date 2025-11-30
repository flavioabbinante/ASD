#include <iostream>
#include "BinaryTreeArray.h"

/* IN QUESTO FILE TESTIAMO L'INSERIMENTO E LA STAMPA DEL SEGUENTE ALBERO

                                    1
                                   / \
                                  2   3
                                 /\   /\
                                4  5 6  7

La stampa usa la versione [valore, sinistro, destro]
Il risultato che ci aspettiamo ( dalla stampa ) è [1, [2, [4, NIL, NIL], [5, NIL, NIL]], [3, [6, NIL, NIL], [7, NIL, NIL]]]

*/

int main() {
    BinaryTreeArray<int> tree;

    // Livello 0
    tree.insRoot(1);

    // Livello 1
    tree.insSx(1, 2);  // figlio sinistro di 1
    tree.insDx(1, 3);  // figlio destro di 1

    // Livello 2
    tree.insSx(2, 4);  // figlio sinistro di 2
    tree.insDx(2, 5);  // figlio destro di 2
    tree.insSx(3, 6);  // figlio sinistro di 3
    tree.insDx(3, 7);  // figlio destro di 3

    std::cout << "Albero binario completo:" << std::endl;
    tree.toString(); // stampa ricorsiva

    return 0;
}

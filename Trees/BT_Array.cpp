#include <iostream>
#include "BinaryTreeArray.h"

/* IN QUESTO FILE TESTIAMO L'INSERIMENTO E LA STAMPA DEL SEGUENTE ALBERO

                                      H
                                 A         C
                               D   L     P   S
                                 O   Q

La stampa usa la versione [valore, sinistro, destro]

*/

int main() {
  BinaryTreeArray<char> tree;

  tree.insRoot('h');

  tree.insSx(1, 'a'); 
  tree.insDx(1, 'c'); 
  
  tree.insSx(2, 'd'); 
  tree.insDx(2, 'l'); 

  tree.insSx(3, 'p'); 
  tree.insDx(3, 's'); 

  tree.insSx(5, 'o'); 
  tree.insDx(5, 'q'); 


  std::cout << "Albero binario completo:" << std::endl;
  tree.toString(); // stampa ricorsiva

  std::cout << "Preorder:" << std::endl;
  tree.preOrder(1);
  std::cout << "\n\n" << std::endl;
  
  std::cout << "InOrder (Simmetrica):" << std::endl;
  tree.inOrder(1);

  std::cout << "\n\n" << std::endl;
  std::cout << "postOrder:" << std::endl;
  tree.postOrder(1);

  std::cout << "\n\n" << std::endl;
  std::cout<< tree.read(tree.getParent(4));

    return 0;
}

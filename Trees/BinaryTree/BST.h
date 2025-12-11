/*
 * Implementazione di un albero binario di ricerca (BST).
 *
 * In un BST ogni nodo ha valori più piccoli a sinistra
 * e più grandi a destra. Questa struttura permette
 * ricerche, inserimenti e cancellazioni efficienti
 * seguendo il percorso corretto senza scansionare tutto.
 */

#ifndef BST_H
#define BST_H

// Eredito i metodi da BinaryTreeList visto che devo ridefinire solo le funzioni di inserimento
#include "BinaryTreeList.h"

template <class T>
class BST: public BinaryTreeList<T>{

    private:
        // Esistono diversi modi per l'implementazione dell'inserimento in un BST
        // Ho preferito la modalità ricorsiva, ma è possibile anche fare quella iterativa
        void insert(T data, TreeNode<T>* &node, TreeNode<T>*parent = nullptr){
            // === Passo base ===
            // Se il nodo corrente è nullptr, significa che siamo arrivati a una una foglia
            // Quindi creo il nodo e lo mando al genitore
            if (node == nullptr) {
                node = new TreeNode<T>(data); // creo il nuovo nodo con il valore
                node->sx = nullptr; // figlio sinistro vuoto
                node->dx = nullptr; // figlio destro vuoto
                node->parent = parent; // assegno il genitore (Opzionale)
                return;                      
            }

            // === Passo induttivo ===
            // Decido se andare a sinistra o a destra seguendo la regola BST
            if (data < node->val) {
                // Se il valore da inserire è più piccolo → scendo a sinistra
                insert(data, node->sx, node);
            } else {
                // Se il valore da inserire è maggiore o uguale → scendo a destra
                insert(data, node->dx, node);
            }    
        }

    public:
        BST(){
            this->root = nullptr;
        }

        // Inserisce un nodo nell'albero
        void insert(T data) {
            insert(data, this->root); 
        }


        // Uso sempre la ricerca ricorsiva ( Per i BST è piu facile )
        TreeNode<T>* search(T element, TreeNode<T>*node){
            // Passo base
            if (node == nullptr || node->val == element)
            {
                return node; // Ritorna nullptr o il nodo 
            }

            // Passo induttivo
            if (element < node->val)
            {
                // visto che val è maggiore vado a sinistra
                return search(element,node->sx);
            }else{
                // Cerco a destra
                return search(element,node->dx);
            }
            
        }

        // Erase è un po difficile 

        // getMin

        // getMax



};





#endif // BST_H
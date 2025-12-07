/* ============================================================
 * ALBERO BINARIO (Binary Tree) Implementazione sequenziale con ARRAY
 * * Implementazione di un albero binario con array utilizzando
 * la classe astratta BinaryTree.h
 * * ============================================================ */


#ifndef BT_ARRAY_H
#define BT_ARRAY_H

#include <iostream>
#include "BinaryTree.h"

// Trattandosi di una implementazione sequenziale definisco il massimo di elementi
#define MAX 33

template <class T>
class BinaryTreeArray : public BinaryTree<T,int>{
    
    private:
        // Nodi dell'albero
        T nodes[MAX];

        // valid[i] = true  -> il nodo esiste
        // valid[i] = false -> il nodo è vuoto/non presente
        bool valid[MAX];

        // Numero di nodi
        int size;

        void printSubTree(int nodeIndex) const override {

            std::cout << "[" << nodes[nodeIndex] << ", ";

            int left = 2 * nodeIndex;
            int right = 2 * nodeIndex + 1;

            // Figlio sinistro
            if (left < MAX && valid[left]) // Modificato per usare MAX e valid
                printSubTree(left);
            else
                std::cout << "NIL";

            std::cout << ", ";

            // Figlio destro
            if (right < MAX && valid[right]) // Modificato per usare MAX e valid
                printSubTree(right);
            else
                std::cout << "NIL";

            std::cout << "]";
        }


    public:

        // Costruttore
        BinaryTreeArray(){
            int i = 0;
            
            for (i = 0; i < MAX; i++){
                valid[i] = false;
            }

            size = 0;         
        }

        // Cancellazione di un sotto-albero
        void erase(int root){
            // Passo Base
            if (root < 1 || root >= MAX || !valid[root]) {
                return;
            }

            // Passo Induttivo
            erase(root*2); // Passo a sinistra
            erase(root*2+1); // Destra
            valid[root] = false;
        }

        // Ritorna l'indice della radice
        int getRoot() const override{

            if (!isEmpty()){
                // La radice è sempre in posizione 1
                return 1;
            }else{
                return -1;
            }

        }

        // Ritorna l'indice di nodo a SINISTRA di un NODO dato
        int getSx(int nodeIndex) const override{
            if (nodeIndex >= 1 && nodeIndex < MAX && valid[nodeIndex]){ // Modificato per indicizzazione >= 1
                if (!sxEmpty(nodeIndex))
                {
                    return nodeIndex * 2;   
                }
            }
            return -1;
        }

        // Ritorna l'indice di nodo a DESTRA di un NODO dato
        int getDx(int nodeIndex) const override{
            if (nodeIndex >= 1 && nodeIndex < MAX && valid[nodeIndex]){ // Modificato per indicizzazione >= 1
                if (!dxEmpty(nodeIndex))
                {
                    return nodeIndex * 2 + 1;   
                }
            }
            return -1;
        }            

        int getParent(int nodeIndex) const override{
            if (nodeIndex/2 > 1 && nodeIndex/2 < MAX && valid[nodeIndex/2])
            {
                return nodeIndex/2;
            }

            return 1;
        }

        // Inserisce la Radice
        void insRoot(T val) override{
            if (isEmpty())
            {
                nodes[1] = val; // Modificato: Radice in posizione 1
                valid[1] = true;
                size++;
            }
        }

        // Inserisce il nodo a SX dato un indice
        void insSx(int indexParent, T val) override{
            int child = 2 * indexParent;
            // Controlla che il genitore sia valido e che il figlio non esista e sia in MAX
            if (indexParent >= 1 && indexParent < MAX && valid[indexParent] && child < MAX && !valid[child])
            {
                nodes[child] = val;
                valid[child] = true;
                size++;
            }   
        }

        // Inserisce il nodo a DX dato un indice
        void insDx(int indexParent, T val) override{
            int child = 2 * indexParent + 1;
            // Controlla che il genitore sia valido e che il figlio non esista e sia in MAX
            if (indexParent >= 1 && indexParent < MAX && valid[indexParent] && child < MAX && !valid[child])
            {
                nodes[child] = val;
                valid[child] = true;
                size++;
            }   
        }

        // Ritorna il VALORE di un nodo
        T read(int index) const override{
            if (valid[index] && index < MAX && index >= 1) // Modificato per indicizzazione >= 1
            {
                return nodes[index];
            }
            
            return T{}; // Valore default vuoto 
        }

        // Sovrascrive il valore di un nodo
        void write(int index, T val ){
            if (valid[index] && index < MAX && index >= 1) // Modificato per indicizzazione >= 1
            {
                nodes[index] = val;
            }
        }

        /* Verifica che il BT sia vuoto
        *
        * Ritorna VERO quando è vuoto
        * Ritorna FALSO quando ha almeno la radice
        */ 
        bool isEmpty() const override{
            // La verifica ottimizzata si basa sul nodo 1
            return !valid[1]; 
        }

        // Verifica se un nodo ha figli a destra o a sinistra
        // Funzione per i nodi di dx: 2*i + 1
        // Funzione per i nodi di sx: 2*i
        bool sxEmpty(int nodeIndex) const override{
            if (nodeIndex >= 1 && nodeIndex < MAX && valid[nodeIndex]) // Modificato per indicizzazione >= 1
            {
                int child = 2 * nodeIndex; // Indice del nodo figlio sinistro
                if (child < MAX && valid[child])
                {
                    return false;
                }
            }
            return true;
        }

        bool dxEmpty(int nodeIndex) const override{
            if (nodeIndex >= 1 && nodeIndex < MAX && valid[nodeIndex]) // Modificato per indicizzazione >= 1
            {
                int child = 2 * nodeIndex + 1; // Indice del nodo figlio destro
                if (child < MAX && valid[child])
                {
                    return false;
                }
            }
            return true;
        }

        void toString() const override{

            if (isEmpty()) {
                std::cout << "[]" << std::endl;
            } else {
                printSubTree(1); // Modificato: radice indice 1
                std::cout << std::endl;
            }

        } 

        // Visita in preorder: R - S - D
        void preOrder(int root) const override{
            // Passo Base
            if (root < 1 || root >= MAX || !valid[root]) {
                return;
            }
            // Visita
            std::cout << nodes[root] << "-";
            // Passo Induttivo
            preOrder(root*2); // Passo a sinistra
            // La sinistra è vuota allora vado a destra
            preOrder(root*2+1);
        }

        // Visita inOrder: S-R-D
        void inOrder(int root) const override{

            // Passo Base
            if (root < 1 || root >= MAX || !valid[root]) {
                return;
            }

            // Passo Induttivo
            inOrder(root*2); // Passo a sinistra
            std::cout << nodes[root] << "-"; // visito 
            inOrder(root*2+1); // Destra
        }

        // Visita postOrder: S-D-R
        void postOrder(int root) const override{

            // Passo Base
            if (root < 1 || root >= MAX || !valid[root]) {
                return;
            }

            // Passo Induttivo
            postOrder(root*2); // Passo a sinistra
            postOrder(root*2+1); // Destra
            std::cout << nodes[root] << "-"; // visito 

        }

    };




#endif // BT_ARRAY_H
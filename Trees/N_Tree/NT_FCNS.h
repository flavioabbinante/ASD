/**
 * Implementazione dell'albero N-ario con rappresentazione FCNS (First Child Next Sibling).
 * 
 * Ogni nodo contiene:
 * - firstChild: puntatore al primo figlio
 * - nextSibling: puntatore al fratello successivo
 * - parent: puntatore al genitore (opzionale)
 * 
 * Questa rappresentazione trasforma un albero n-ario in una struttura binaria,
 * permettendo un numero illimitato di figli per nodo.
 * 
 */

#ifndef NT_FCNS_H
#define NT_FCNS_H

#include "N_aryTree.h"
#include "../../Queue/Queue.h"
#include <iostream>

// Classe Nodo per l'albero n-ario

template <class DataType> class NaryTree_FCNS;

template <class DataType>
class TreeNode {
    public:
        // Contenuto informativo del nodo
        DataType data;
        // Primo figlio della root
        TreeNode* firstChild;
        // Fratello successivo al figlio
        TreeNode* nextSibling;
        // Nodo genitore
        TreeNode* parent;
    
    // Il friend deve usare la classe albero corretta
    friend class NaryTree_FCNS<DataType>; 
};

template <class DataType>
class NaryTree_FCNS:public NaryTree<DataType,TreeNode<DataType>*>
{
    private:
        TreeNode<DataType>* root;

    public:
        NaryTree_FCNS() : root(nullptr) {}; // Costruttore vuoto

        // Distruttore TODO

        // === GETTERS ===

        TreeNode<DataType>* getRoot() const override{
            return root;
        } 

        TreeNode<DataType>* getFirstChild(TreeNode<DataType>* node) const override{
            if (node != nullptr)
            {
                return node->firstChild;
            }

            return nullptr;            
        }

        TreeNode<DataType>* getNextSibling(TreeNode<DataType>* node) const override{
            if (node != nullptr)
            {
                return node->nextSibling;
            }
            return nullptr;
        }

        TreeNode<DataType>* getParent(TreeNode<DataType>* child) const override{
            if (child != nullptr && child != root)
            {
                return child->parent;
            }
            return nullptr;            
        }

        DataType getValue(TreeNode<DataType>* node) const override{
            if (node != nullptr)
            {
                return node->data;
            }else{
                return DataType{ };            
            }
        }

        int getWidth() const override{
            int w = 0;
            Queue<TreeNode<DataType>*> q;
            TreeNode<DataType>* child;
            TreeNode<DataType>* current; 

            // Inizio dalla radice
            q.enqueue(root);

            while (!q.isEmpty())
            {
                int levelLen = q.getSize(); // Prendo la lunghezza del livello in cui mi trovo
                w = std::max(w,levelLen); // Trovo il massimo

                // Ma ora ho bisogno di trovare gli altri figli 
                for (int i = 0; i < levelLen; i++)
                {
                    current = q.dequeue();
                    
                    // Adesso metto i figli nella coda
                    child = current->firstChild;
                    while (child != nullptr)
                    {
                        q.enqueue(child);
                        child = child->nextSibling;
                    }
                }
                
            }

            return w;
        }

        int getDepth(TreeNode<DataType>* node) const override {
            
            int d = 0; // Depth

            if (node == nullptr)
            {
                return 0;
            }

            TreeNode<DataType>* child = node->firstChild;

            while (child != nullptr)
            {
                d = std::max(d,getDepth(child));
                child = child->nextSibling;
            }
            
            return 1 + d;

        }

        // === INSERIMENTO ===
        

        void setRoot(DataType val) override{             
            // Si assume che l'albero sia vuoto, se si vuole cambiare cambiare il contenuto
            // Informativo del nodo, usa write()
            root = new TreeNode<DataType>();
            root->data = val;
        }

        void insertChild(TreeNode<DataType>* root, DataType value) override {
            if (root != nullptr)
            {
                // Inizializzazione del nuovo figlio
                TreeNode<DataType>* newChild = new TreeNode<DataType>();
                newChild->data = value;
                newChild->parent = root;

                /**
                 * Adesso devo inserire il nodo, ci sono due casi:
                 * 1) Il primo figlio non esiste -> Lo inserisco
                 * 2) Il primo figlio esiste -> Devo inserirlo come fratello, chiamo insertSibling
                 */

                if (root->firstChild == nullptr)
                {
                   root->firstChild = newChild;
                } else {
                    // Devo inserirlo come ultimo fratello
                    TreeNode<DataType>* lastChild = root->firstChild;
                    while (lastChild->nextSibling != nullptr)
                    {
                        lastChild = lastChild->nextSibling;
                    }
                    // Inserisco come fratello
                    insertSibling(lastChild, value);
                    delete newChild; // Non mi serve più perché insertSibling ne crea uno nuovo                     
                }
            }
            return;
        }

        void insertSibling(TreeNode<DataType>* lastSibling, DataType value) override{
            
            TreeNode<DataType>* newSibling = new TreeNode<DataType>();
            newSibling->data = value;

            newSibling->parent = lastSibling->parent;
            lastSibling->nextSibling = newSibling;
        }

        // === MODIFICA ===
        void write(TreeNode<DataType>* node,DataType newVal) override{
            if (node != nullptr)
            {
                node->data = newVal;
            }
            
        }

        // == ELIMINAZIONE ==
        // Utilizzo l'eliminazione con il postOrder
        void eraseSubtree(TreeNode<DataType>* node) override{
            // Passo Base
            if (node == nullptr)
            {
                return;
            }

            // Cancello ricorsivamente tutti i figli
            eraseSubtree(node->firstChild);
            // Al termine della chiamata ricorsiva cancello ricorsivamente tutti i fratelli
            eraseSubtree(node->nextSibling);
            delete node;            
        }

        // === CONTROLLI ===
        bool isEmpty() const override {
                return root == nullptr;
            }

        bool isLeaf(TreeNode<DataType>* node) const override {
                if (node == nullptr) return false;
                return node->firstChild == nullptr;
            }

        bool isLastSibling(TreeNode<DataType>* node) const override {
                if (node == nullptr) return false;
                return node->nextSibling == nullptr;
            }        

        // === ALGORITMI DI VISITA ===
        /**
         * La visita in  PREORDER negli alberi n-ari prevede l'ordine di visita con:
         * Radice -> Figli -> Fratelli
         * Implementazione ricorsiva
         */
        void preOrder(TreeNode<DataType>* node) const override{

            // Passo Base
            if (node != nullptr)
            {
                // Visito la radice
                std::cout << node->data << " - ";
                // Passo ai figli
                preOrder(node->firstChild);
                // Fratelli
                preOrder(node->nextSibling);
            }

                        
        }

        // VISITA IN POST ORDER: FIGLI -> FRATELLI -> RADICE ( Motivo per cui lo uso per eliminare i subtree)
        void postOrder(TreeNode<DataType>* node) const override{
                // Passo Base
                if (node != nullptr)
                {
                    // Passo ai figli
                    preOrder(node->firstChild);

                    // Fratelli
                    preOrder(node->nextSibling);

                    // Visito
                    std::cout << node->data << " - ";

                }
        }

        // Breath First Search
        /**
         * L'algoritmo BFS esplora l'albero n-ario livello per livello.
         *
         * 1.Inizia dalla radice (livello 0).
         * 2.Visita tutti i nodi al livello attuale (es. tutti i figli della radice, livello 1).
         * 3.Passa poi al livello successivo (livello 2) e ripete il processo.
         *
         * Principio: Utilizza una CODA FIFO per mantenere traccia dei nodi da visitare,
         * garantendo che un nodo non sia visitato finché tutti i suoi fratelli e tutti i nodi
         * dei livelli precedenti non siano stati esaminati.
         */
        void bfs(TreeNode<DataType>* node) const override{

            Queue<TreeNode<DataType>*> q;

            // Inizio dalla radice (1)
            q.enqueue(node);

            while (!q.isEmpty())
            {
                TreeNode<DataType>* current = q.dequeue();

                // (2) Visito il livello attuale
                std::cout << current->data << " ";

                // (3) Aggiungo alla coda tutti i figli del nodo
                TreeNode<DataType>* child = current->firstChild;
                while (child != nullptr) {
                    q.enqueue(child);
                    child = child->nextSibling;
                }

            }
            

        }
};


#endif // NT_FCNS_H
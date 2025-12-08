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
 */

#ifndef NT_FCNS_H
#define NT_FCNS_H

#include "N_aryTree.h"

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
class NT_FCNS:public NaryTree<DataType,TreeNode<DataType>*>
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
            }
            return nullptr;            
        }

        // === INSERIMENTO ===

        void setRoot(DataType val) override{             
            // Si assume che l'albero sia vuoto, se si vuole cambiare cambiare il contenuto
            // Informativo del nodo, usa write()
            root = new TreeNode<DataType>();
            root->data = val;
        }

        void insertChild(TreeNode<DataType> parent, DataType value) override{
            if (parent != nullptr)
            {
                // Inizializzazione del nuovo figlio
                TreeNode<DataType>* newChild = new TreeNode<DataType>();
                newChild->data = value;

                /**
                 * Adesso devo inserire il nodo, ci sono due casi:
                 * 1) Il primo figlio non esiste -> Lo inserisco
                 * 2) Il primo figlio esiste -> Devo inserirlo come fratello, chiamo insertSibling
                 */

                if (parent->firstChild == nullptr)
                {
                   parent->firstChild = newChild;
                }else{
                    // Devo inserirlo come ultimo fratello
                    // Quindi ciclo tra i fratelli
                    TreeNode<DataType> lastChild = parent->firstChild;
                    while (lastChild != nullptr)
                    {
                        lastChild = lastChild->nextSibling;
                    }
                    // Se sono uscito dal loop vuol dire che sono arrivato alla fine dei figli
                    // Quindi chiamo insertSibling() per inserirlo come fratello ( Riuso del codice )
                    insertSibling(newChild,value);
                    delete newChild; // Non mi serve piu perche insertSibling ne crea uno nuovo                     
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
};


#endif // NT_FCNS_H
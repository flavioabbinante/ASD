
/* 

    ALBERI BINARI IMPLEMENTATI CON LISTA LINKATA

*/

#ifndef BINARY_TREE_LIST_H
#define BINARY_TREE_LIST_H

#include <iostream>
#include "NTree.h"
#include "BinaryTree.h"

#include "../Stack/Stack.h"
#include "../Queue/Queue.h"

template <class T>
class BinaryTreeList: public BinaryTree<T , TreeNode<T>*>{
    private:
        TreeNode<T> * root;

        void printSubTree(TreeNode<T>* tn) const {
            if (tn == nullptr) {
                std::cout << "NIL";
                return;
            }
        
            std::cout << "[" << tn->val << ", ";
        
            // Figlio sinistro
            printSubTree(tn->sx);
            std::cout << ", ";
        
            // Figlio destro
            printSubTree(tn->dx);
            std::cout << "]";

        }

    public:
        
        // Costruttore
        BinaryTreeList(){
            root = nullptr;
        }

        
        ~BinaryTreeList(){
            // Per la cancellazione dell'albero uso il POST ORDER ricorsivo 
            
            postOrderDistruttore(root);

            root = nullptr;
        
        }

        // Cancellazione di un sotto-albero
        void erase(TreeNode<T>* &root){
            // Passo Base
            if (root == nullptr) {
                return;
            }

            // Passo Induttivo
            erase(root->sx); // Passo a sinistra
            erase(root->dx); // Destra
            delete root;
            root = nullptr; 
        }

        //  == Inserimento ==

        void insRoot(T e) override {
            if (isEmpty())
            {
                root = new TreeNode<T>(e);
            }
            
        }

        void insDx(TreeNode<T>* tn, T e) override{
            
            TreeNode<T> * node = new TreeNode<T>();

            if (dxEmpty(tn))
            {
                node->parent = tn;
                node->val = e;
                tn->dx = node;
            }
            
        }

        void insSx(TreeNode<T>* tn, T e) override {
            
            TreeNode<T>* node = new TreeNode<T>();

            if (sxEmpty(tn)) 
            {
                node->parent = tn;
                node->val = e;
                tn->sx = node;
            }

        }

        // == Getters ==

        TreeNode<T>* getRoot() const override{
            if (!isEmpty())
            {
                return root;
            }else{
                return nullptr;
            }
            
        }

        TreeNode<T>* getSx(TreeNode<T>* tn) const override{
            if (!sxEmpty(tn))
            {
                return tn->sx;
            }
            
            return nullptr;
        }

        TreeNode<T>* getDx(TreeNode<T>* tn) const override{
            if (!dxEmpty(tn))
            {
                return tn->dx;
            }
            
            return nullptr;
        }

        TreeNode<T>* getParent(TreeNode<T>* tn) const override{
            if (tn != root)
            {
                return tn->parent;
            }
            
            return nullptr;
        }
        
        // Lettura e Modifica
        T read(TreeNode<T>* tn) const override{
            if (tn != nullptr)
            {
                return tn->val;
            }
            return T { }; // Possiamo anche creare un Exeption
        }

        void write(TreeNode<T>* tn, T e) override{
            if (tn != nullptr)
            {
                tn->val = e;
            }
            
        }

        // Controlli su nodi vuoti
        bool isEmpty() const override{
            return root == nullptr;
        }

        bool sxEmpty(TreeNode<T>* tn) const override{
            return tn->sx == nullptr;
        }

        bool dxEmpty(TreeNode<T>* tn) const override{
            return tn->dx == nullptr;
        }


        // Stampa
        void toString() const override {
            
            if (isEmpty())
            {
                std::cout << "[]" << std::endl;
            }else{
                printSubTree(root);
                std::cout << std::endl;
            }

        }

        
        // Algoritmi di visita 
        // Algoritmo di visita PRE-ORDER ( In profondità ) versione iterativa
        // Con uso di uno STACK 
        void preOrder(TreeNode<T>* root) const override{

            Stack<TreeNode<T>*> stack; 

            if (root == nullptr)
            {
                return;
            }

            stack.push(root);

            while (!stack.isEmpty())
            {
                root = stack.pop();
                std::cout << root->val << "-";
                if (!dxEmpty(root))
                {
                    stack.push(root->dx);
                }

                if (!sxEmpty(root))
                {
                    stack.push(root->sx);
                }
                   
            } 

        }

        // In Order RICORSIVO
        void inOrder(TreeNode<T>* root) const override{
            if (root == nullptr)
            {
                return;
            }

            inOrder(root->sx);
            std::cout << root->val << "-";
            inOrder(root->dx);
            
        }

        // PostOrder ricorsivo
        void postOrder(TreeNode<T>* root) const override{
            if (root == nullptr)
            {
                return;
            }

            postOrder(root->sx);
            postOrder(root->dx);
            std::cout << root->val << "-";
     
        }

        // PostOrder usato come distruttore
        void postOrderDistruttore(TreeNode<T>* root){
            if (root == nullptr)
            {
                return;
            }

            postOrderDistruttore(root->sx);
            postOrderDistruttore(root->dx);
            
            delete root;
        }
        
        
        // Breath First Search
        /* 
           Serve a trovare la profondità minima per cercare qualcosa
           Generare la vista dell'albero livello per livello
        */
        void BFS(TreeNode<T>* root) const{
            
            /* La BFS ha bisogno di una CODA perchè c'è bisogno di tenere
               traccia dei nodi al livello sottostante che verranno visitati
               al termine del livello corrente
            */ 
            Queue<TreeNode<T>*> coda;
            TreeNode<T>* current;

            // Se l'albero è vuoto, non c'è nulla da visitar            
            if (!root)
            {
                return;
            }

            // Inizio dalla radice
            coda.enqueue(root);

            // Finchè ci saranno nodi nella coda, l'albero non sarà finito
            while (!coda.isEmpty())
            {

                current = coda.dequeue(); // Estraggo il primo dalla coda 

                std::cout << current->val << " "; // Visito il nodo PER LA PRIMA VOLTA

                // Inserisco in coda i nodi figli che dovrà visitare al prossimo livello (se esistono)
                // Metto prima il sinistro perche la BFS vuole la lettura da SX verso DX
                if (!sxEmpty(current))
                {
                    coda.enqueue(current->sx);
                }
                
                if (!dxEmpty(current))
                {
                    coda.enqueue(current->dx);
                }

            }           
        }
    };


#endif
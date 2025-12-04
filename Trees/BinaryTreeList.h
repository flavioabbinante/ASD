
/* 

    ALBERI BINARI IMPLEMENTATI CON LISTA LINKATA

*/

#ifndef BINARY_TREE_LIST_H
#define BINARY_TREE_LIST_H

#include <iostream>
#include "NTree.h"
#include "BinaryTree.h"

#include "../Stack/Stack.h"

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

    };


#endif
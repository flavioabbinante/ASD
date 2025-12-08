/* INTERFACCIA PER L'IMPLEMENTAZIONE DELL'NODO DELL'ALBERO N ARIO
*  
* 
*/

#ifndef NODE_TREE_H
#define NODE_TREE_H

template <class T> class BinaryTreeList;

template <class T>
class TreeNode{
    public:
        TreeNode<T> * parent;
        TreeNode<T> * sx;
        TreeNode<T> * dx;

        T val;

        // Vuoto
        TreeNode(){
            parent = nullptr;
            sx = nullptr;
            dx = nullptr;            
        }

        // Con elemento
        TreeNode(T e){
            parent = nullptr;
            sx = nullptr;
            dx = nullptr;
            val = e;
        }

        

    friend class BinaryTreeList<T>;
};


#endif
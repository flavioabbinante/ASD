/*
    Implementazione della classe Stack ( Pila ) LIFO con i seguenti metodi usando l'implementazione con Puntatori
    - push() inserisce un elemento in cima alla pila
    - pop() estrae l'ultimo elemento in cima alla pila
    - isEmpty() Verifica che sia vuota
    - top() Ritorna la testa della pila
    */


#ifndef STACK_H
#define STACK_H

#include <iostream>

template <class T> class Stack;

// Classe Nodo
template<class T> 
class StackNode{
    private:
        T val;
        StackNode<T> * next = nullptr;
    
    friend class Stack<T>;
};

template<class T> 
class Stack
{
private:
    StackNode<T> * top;
public:
    Stack(){
        top = nullptr;
    };

    ~Stack(){
        while (!isEmpty()){
            pop();
        }
             
    }

    /* == FUNZIONE PUSH ==
        Inserisce un elemento in testa alla coda 
    */ 
    void push(T e){
        StackNode<T> * node = new StackNode<T>();
        node->val = e;

        // Sposto l'elemento attualmente in testa al successivo di quello nuovo 
        node->next = top;

        // Rendo la nuova testa il nodo appena inserito
        top = node;
        
    } 
    
    /* == FUNZIONE POP ==
        Rimuove e ritorna il nodo in cima alla Pila
    */
    T pop(){

        StackNode<T> * toDelete;
        
        if(!isEmpty()){
            toDelete = top;
            T popVal = toDelete->val; // Valore del nodo cancellato
            top = top->next;
            delete toDelete;
            return popVal;
        }

        return nullptr;
        
    }
    
    bool isEmpty(){
        return top==nullptr;
    }
    
    /* == FUNZIONE TOP ==
        Ritorna l'elemento in top della pila senza cancellarlo
    */
    T getTop(){
        if (!isEmpty()){
            return top->val;
        }
        return -1;
    }

    /* == STAMPA LA PILA
    */
    void toString() const{
        StackNode<T> * curr = top;

        while (curr != nullptr)
        {
            std::cout << curr->val << " -> ";
            curr = curr->next;
        }

        std::cout << "BOTTOM" << std::endl;
    }

    
    
};



#endif
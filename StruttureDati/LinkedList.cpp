/*
    Implementazione della Linked List singolarmente collegata.
    Con i principali metodi di inserimento cancellazione ricerca ed aggiornamento
    con alcune funzioni utili per risolvere gli esercizi
*/

#include <iostream>

template<class T> class LinkedList;

template<class T> 
class ListNode{
    private:
        T val;
        ListNode<T> * next = nullptr;
    
    friend class LinkedList;
};

template <class T> 
class LinkedList{

    private:
        ListNode <T>* head = nullptr;

    public:

        /*
            Costruttore: Imposta a null il puntatore head
        */
        LinkedList(){
            head = nullptr;
        }

        
        ~LinkedList() {
            ListNode<T> *curr = head; // Inizializza 'curr' al primo nodo della lista (head)
            ListNode<T> *nxt; // Puntatore temporaneo per memorizzare il nodo successivo
        
            // Ciclo finché ci sono nodi da eliminare
            while (curr != nullptr) {
                nxt = curr->next; // Salva il puntatore al nodo successivo
                delete curr; // Elimina il nodo corrente per liberare memoria
                curr = nxt; // Passa al nodo successivo
            }
            // Alla fine, tutti i nodi sono stati deallocati; posso anche fare:
            head = nullptr;
        }

        /*
            === FUNZIONI DI INSERIMENTO ===
        
            1. pushFront: inserisce un nuovo nodo all'inizio della lista.
            2. pushBack: inserisce un nuovo nodo alla fine della lista.
            3. insertAt: inserisce un nuovo nodo in una posizione specifica.
            4. insertSorted: inserisce un nuovo nodo mantenendo la lista ordinata.
            5. insertAfter: inserisce un nuovo nodo subito dopo un nodo specifico.
        */

        /*
            Inserisce un nuovo nodo all'inizio della lista
            Parametro: Elemento da inserire
        */
        void pushFront(T e){
            
            ListNode<T> * newNode = new ListNode<T>();
            newNode->val = e; // Assegno il valore al nodo

            // Il nuovo nodo punta all'attuale head
            newNode->next = head; 
            
            // Aggiorno head per puntare al nuovo nodo
            head = newNode;

        }

        /*
            Inserisce un nuovo nodo alla fine della lista
            Parametro: Elemento da inserire
        */
        void pushBack(T e){
            
            ListNode<T>  * curr = head; 
            ListNode<T>  * prec = curr; 
            ListNode<T> * newNode = new ListNode<T>(); // Nuovo nodo da inserire
            
            newNode->val = e; 

            if (isEmpty()){ 
                head = newNode;
            }else{
                while (curr != nullptr)
                {
                    prec = curr;
                    curr = curr->next;
                }

                prec->next = newNode;
                newNode->next = nullptr;
            }

        }


        
        bool isEmpty(){
            return head==nullptr;
        }
};
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

        /*
            Inserisce un elemento in una posizione specifica
            Se l'indice è > i, l'operazione non viene svolta
            si potrebbe pensare di inserire l'elemento alla fine
        */
        void insertAt(int index,T e){
            ListNode<T> * curr = head;
            ListNode<T> * tmp;

            int i = 0;


            if (!isEmpty()){

                if (index==0){
                    pushFront(e);
                }else{
                    while (curr != nullptr && i < index-1)
                    {
                        curr = curr->next;
                        i++;
                    }

                    if (curr != nullptr){
                        ListNode<T>* newNode = new ListNode<T>();
                        newNode->val = e;

                        tmp = curr->next;
                        curr->next = newNode;
                        newNode->next = tmp;
                    } 
                }       
                
            }else{
                pushFront(e);
            }
       }
        
       /*
            Inserisce un nodo in una lista ordinata
       */
        void insertSorted(T, e);

        // ============================================================ //

        /*
            === FUNZIONI DI CANCELLAZIONE ===
        
            1. removeFront: rimuove un nodo all'inizio della lista.
            2. removeBack: rimuove un nodo alla fine della lista.
            3. removeAt: rimuove un nodo in una posizione specifica.
            4. removeValue: rimuove un nodo con un determinato valore.

        */

        // Rimuove il nodo all'inizio
        void removeFront(){

            ListNode<T> * toDelete;

            if (!isEmpty()){
                toDelete = head;
                head = head->next;
                delete toDelete;            
            }

        }

        // Rimuove il nodo alla fine della lista
        void removeBack(){

            ListNode<T> * curr = head;
            ListNode<T> * prec = head;

            if (!isEmpty())
            {

                if(head->next == nullptr){
                    delete head;
                    head = nullptr;
                }
                else{
                    while (curr->next != nullptr) {
                        prec = curr;
                        curr = curr->next;
                    }

                    prec->next = nullptr;
                    delete curr;  
                }

            }
            
        }

        // Rimuove il nodo ad un determinato indice 
        

        bool isEmpty(){
            return head==nullptr;
        }
};
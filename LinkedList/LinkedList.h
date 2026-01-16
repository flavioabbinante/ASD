/*
    Implementazione della Linked List singolarmente collegata.
    Con i principali metodi di inserimento cancellazione ricerca ed aggiornamento
    con alcune funzioni utili per risolvere gli esercizi
*/

/*
== FUNZIONI DI INSERIMENTO ==
- pushFront(T e)
- pushBack(T e)
- insertAt(int index, T e)
- insertSorted(T e)
- inserimentoOrdinato (T e) -- TODO

== FUNZIONI DI CANCELLAZIONE ==
- removeFront()
- removeBack()
- removeAt(int index)

== FUNZIONI DI MODIFICA ==
- searchElement(T e)
- selectionSort()
- changeAt(T e, int index)

== FUNZIONI DI UTILITÀ ==
- toString() const
- reverse()
- isEmpty() const
- isSorted() -- TODO
- merge(LinkedList<T> * list)
- divide(LinkedList<T> * left, LinkedList<T> * right)
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template<class T> class LinkedList;

template<class T> 
class ListNode{
    private:
        T val;
        ListNode<T> * next = nullptr;
    
    friend class LinkedList<T>;
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
        void insertSorted(T e);

        // ============================================================ //

        /*
            === FUNZIONI DI CANCELLAZIONE ===
        
            1. removeFront: rimuove un nodo all'inizio della lista.
            2. removeBack: rimuove un nodo alla fine della lista.
            3. removeAt: rimuove un nodo in una posizione specifica.

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
        void removeAt(int index){
            ListNode<T> * curr = head;
            ListNode<T> * prec = head;
            int i = 0;

            if (!isEmpty()){
                if (index == 0){
                    removeFront();
                }else{

                    while (curr != nullptr && i < index)
                    {
                        i++;
                        prec = curr;
                        curr = curr->next;
                    }

                    prec->next = curr->next;
                    delete curr;
                    
                }
            }
        }

        /*
            === FUNZIONI DI MODIFICA ===
            1. searchElement: Ritorna l'indice di un certo elemento
            2. selectionSort: Ordina la lista con il Selection Sort
            3. changeAt: cambia un elemento all'indice 
        */

        // Ricerca lineare di un elemento
        int searchElement(T e){

            ListNode<T> * curr = head;
            int index = 0;
            bool trovato = false;

            if (!isEmpty()){
                while (curr != nullptr)
                {
                    if(curr->val == e){
                        trovato = true;
                    }
                    index++;
                    curr = curr->next;
                }

            }
            
            
            return index;

        }

        // Selection Sort
        void selectionSort() {

            ListNode<T> * i = head;
            ListNode<T> * j = head;
            T tmp;

            while (i != nullptr)
            {
                while (j != nullptr)
                {
                    if (i->val > j->val)
                        tmp = i->val;
                        i->val = j->val;
                        j->val = tmp;

                    j = j->next;
                }

                i = i->next;                
            }
            
        }
        
        void changeAt(T e,int index){
            ListNode<T> * curr = head;
            int i = 0;

            if (!isEmpty()){
                while (curr->next != nullptr && i < index)
                {
                    curr = curr->next;
                    i++;
                }

                    curr->val = e;                    
            }            
        }

        // Ritorna il valore ad un indice
        T getAt(int index){
            ListNode<T> * curr = head;
            int i = 0;

            if (!isEmpty()){
                while (curr->next != nullptr && i < index)
                {
                    curr = curr->next;
                    i++;
                }                
            }

            return curr->val;
        }

        /*
            === FUNZIONI DI UTILITÀ ===
        
            1. toString: stampa la lista.
            2. reverse: inverte la lista.
            3. isEmpty: verifica se la lista è vuota.
            4. isSorted Controlla se è ordinata
            5. merge: Merge di due liste ordinate ( Utile per il mergesort )
            6. divide: divide la lista in due liste ( Utile per il mergesort )

        */

        // Stampa la lista
        void toString() const{
            ListNode<T> * curr = head;

            while (curr != nullptr)
            {
                std::cout << curr->val << " -> ";
                curr = curr->next;
            }

            std::cout << "END" << std::endl;
        }

        // Inverte una LL
        void reverse(){

            ListNode<T> * curr = head;
            ListNode<T> * next;
            ListNode<T> * prev = nullptr;

            if (!isEmpty()){
                while (curr != nullptr)
                {
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
                
            }

            head = prev;
        }

        void insListaOrdinata(T element){
            ListNode<T> * curr = head;
            ListNode<T> * prev = nullptr;
            ListNode<T>* newNode = new ListNode<T>();
            newNode->val = element;

            // Cambia qui per ordinamento crescente (<) o decrescente (>) 
            
            // Ordinamento crescente:
            
            // Qui vado avanti fin quando non trovo un cazzo di elemento più grande
            while (curr != nullptr && curr->val < element) {
                prev = curr;
                curr = curr->next;
            }

            // Questo è l'inserimento in testa
            if (prev == nullptr) {
                newNode->next = head;
                head = newNode;
            // Questo è l'inserimento in mezzo ( nanz o cazz )
            } else {
                newNode->next = curr;
                prev->next = newNode;
            }
        }


    

        // Controlla se la lista è vuota
        bool isEmpty() const {
            return head==nullptr;
        }

        // Merge di questa e un altra lista
        LinkedList merge(LinkedList<T> * list) { // Metto const perche non modifico la lista originale
            LinkedList<T> result = LinkedList<T>(); // Creiamo la lista 

            ListNode<T> * curr1 = head; // Nodo che scorre la lista 1
            ListNode<T> * curr2 = list->head; // Nodo che scorre la lista 2

            // Finche uno dei due non finisce
            while (curr1 && curr2)
            {
                // Se curr1 è > curr2 allora lo inserisce alla fine della lista
                if (curr1->val < curr2->val){
                    result.pushBack(curr1->val);
                    curr1 = curr1->next; // Mando avanti c1 perche è stato inserito
                }else{
                    result.pushBack(curr2->val);
                    curr2 = curr2->next; // Mando avanti c2 perche è stato inserito
                }
            }

            // Adesso una delle due liste sarà sicuramente vuota quindi inserisco
            // i nodi rimanenti all'interno della lista risultato.
            while (curr1 != nullptr)
            {
                result.pushBack(curr1->val);
                curr1 = curr1->next;
            }
            
            while (curr2 != nullptr)
            {
                result.pushBack(curr2->val);
                curr2 = curr2->next;
            }
            
            return result; // Ritorno risultato 

        }
    
        // Divide 
        void divide(LinkedList<T> * left, LinkedList<T> * right ){

            if (head == nullptr || head->next == nullptr) {
                left->head = head;
                right->head = nullptr;
                return;
            }

            ListNode<T> * slow = head;
            ListNode<T> * fast = head;
            ListNode<T>* prec = nullptr;

            while (fast != nullptr && fast->next != nullptr)
            {
                prec = slow;
                slow = slow->next;
                fast = fast->next->next;
            }

            if (prec != nullptr)
                prec->next = nullptr;

            left->head = head;
            right->head = slow;

        }

        int size(){

            ListNode<T> * curr = head;
            int c = 0;

            while (curr != nullptr)
            {
                curr = curr->next;
                c++;
            }

            return c;            
        }

    };


#endif
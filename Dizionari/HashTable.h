/* === HASH TABLE CON HASH CHIUSO ===
 * Implementazione di un dizionario usando hashing con linear probing.
 * Ogni bucket contiene al massimo una coppia (key, value).
 * Le collisioni vengono risolte cercando il prossimo bucket libero.
 * La ha uno spazio fisico limitato, ma è possibile estenderla 
 * ricalcolando gli hash e mantenendo le operazioni di ricerca O(1)
 */


#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Dictionary.h"
#include "Hash.h"
#include <iostream>



template <class K, class T>
class HashTable: public Dictionary<K,T>{
    
    private:
        Pair<K,T>** table; // Array di puntatori ai bucket, ogni bucket contiene un Pair oppure nullptr se è vuoto
        Hash<K> hashFunction; // Funzione di Hash che calcola l'indice in base ad una funzione dichiarata in Hash
        int size; // Numero di coppie nella tabella
        int divisor; // Numero di bucket della tabella; usato per calcolare l'indice con l'hash
    
        static Pair<K,T>* const DELETED;

    public:
       
        // Costruttore
        HashTable(int div){
            
            divisor = div;
            size = 0;

            table = new Pair<K,T>*[divisor]; // Allocazione dell'array di puntatori 

            for (int i = 0; i < divisor;i++){
                table[i] = nullptr; // Imposto tutti i bucket vuoti
            }

    }

        /*Distruttore
        ~HashTable(){
        int i;

        for (i = 0; i < divisor; i++)
        {
            if (table[i] != nullptr)
            {
                delete table[i];
            }
            
        }
        
        delete table[];
    }
        */

        // Inserimento di una coppia
        void insert(Pair<K,T>& pair) override{

            int index = hashFunction(pair.key) % divisor;
            int start = index; 
            
            // Cerca il primo slot libero (nullptr o DELETED)
            while (table[index] != nullptr && table[index] != DELETED)
            {
                index = (index + 1) % divisor; 
                if (index == start) // Tabella piena
                {
                    std::cout << "TABELLA PIENA" << std::endl;
                    return;
                }
            }
            
            table[index] = new Pair<K,T>(pair); 
            size++;
        }

        // Inserimento di una coppia con parametri diversi
        void insert(K key, T val) override{

            int index = hashFunction(key) % divisor;
            int start = index; 
            
            // Cerca il primo slot libero (nullptr o DELETED)
            while (table[index] != nullptr && table[index] != DELETED)
            {
                index = (index + 1) % divisor; 
                if (index == start) // Tabella piena
                {
                    std::cout << "TABELLA PIENA" << std::endl;
                    return;
                }
            }
            
            table[index] = new Pair<K,T>(key,val); 
            size++;
        }

        // Modifica di un valore
        void modify(const K& key, const T& e) override{
            int index = hashFunction(key) % divisor;
            int start = index;

            do
            {
                if (table[index] != DELETED && table[index]->key == key){
                    table[index]->value = e;
                    return;
                }

                index = (index + 1) % divisor;
            } while (index != start);
            
            
        }

        // Cancella una coppia con una determinata Chiave (IMPLEMENTAZIONE CON MARCATORE/TOMBSTONE)
        void erase(const K& key) override {

            int index = hashFunction(key) % divisor;

            // 1. TROVA L'ELEMENTO: Scansione Lineare (Linear Probing)
            // Continua a cercare finché non trova un bucket MAI USATO (nullptr).
            // Se incontra DELETED, prosegue (lo "salta") per non interrompere la catena di collisione.
            while (table[index] != nullptr) {
                
                // Se NON è il marcatore DELETED E la chiave corrisponde, abbiamo trovato l'elemento
                if (table[index] != DELETED && table[index]->key == key) {
                    
                    // 2. CANCELLAZIONE FISICA e MARCATURA LOGICA
                    
                    // a) Libera la memoria dinamica dell'oggetto Pair
                    delete table[index];
                    
                    // b) Sostituisce il puntatore con il marcatore di cancellazione (Tombstone)
                    table[index] = DELETED; 
                    
                    size--;
                    return; // Eliminazione completata
                }

                // Sposta all'indice successivo (linear probing)
                index = (index + 1) % divisor;
            }

            // Se il loop termina, l'elemento non è stato trovato (raggiunto nullptr).
        }

        // Ricerca di un elemento data una chiave
        Pair<K,T>* find(const K& key) const override {

            int index = hashFunction(key) % divisor;

            // Scansione lineare finché non trova un bucket nullptr (mai usato)
            while (table[index] != nullptr) {
                
                // Se NON è il Tombstone DELETED e la chiave corrisponde
                if (table[index] != DELETED && table[index]->key == key) {
                    return table[index]; // Elemento trovato
                }
                
                // Procede all'indice successivo (linear probing)
                index = (index + 1) % divisor;
            }
            
            return nullptr; // Elemento non trovato
        }

        // FUNZIONE DI STAMPA
        void toString()
        {
            std::cout << "[";

            for (int i = 0; i < divisor; ++i) {
                
                if (table[i] == nullptr)
                    std::cout << "-"; // Slot mai usato

                else if (table[i] == DELETED)
                    std::cout << "~"; // Slot cancellato (Tombstone)
                
                else // Elemento valido
                    std::cout << "(\"" << table[i]->key << "\"," << table[i]->value << ")";
            
                if (i != divisor - 1)
                    std::cout << ",";
            }

            std::cout << "]" << std::endl;           
        }

        // Ritorna VERO se è vuota
        bool isEmpty(){
            return size==0;
        }

        // Ritorna numero di coppie
        int getSize() const override{
            return size;
        } 

};


/*
 * DEFINIZIONE DEL MARCATORE DI CANCELLAZIONE (TOMBSTONE)
 * --------------------------------------------------------
 * Questo puntatore statico e costante funge da "pietra tombale" (Tombstone).
 * Viene creato forzando la conversione del valore intero (-1) in un puntatore 
 * (tramite reinterpret_cast). Questo garantisce che:
 * 1. Non sia un indirizzo di memoria valido (non punta a un oggetto Pair reale).
 * 2. Non sia nullptr (che in scansione lineare significa "fine della catena").
 *
 * FUNZIONAMENTO:
 * - Quando un elemento viene cancellato, al suo posto viene messo DELETED.
 * - La RICERCA (e l'ERASE) DEVE attraversare DELETED, continuando la scansione.
 * - L'INSERIMENTO PUÒ riutilizzare un bucket marcato DELETED, trattandolo 
 * come libero per l'inserimento di una nuova coppia.
 */
template<class K, class T>
Pair<K,T>* const HashTable<K,T>::DELETED = reinterpret_cast<Pair<K,T>*>(-1);


#endif
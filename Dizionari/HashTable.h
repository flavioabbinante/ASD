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


template<class T> class Hash;


template <class K, class T>
class HashTable: public Dictionary<K,T>{
    
    private:
        Pair<K,T>** table; // Array di puntatori ai bucket, ogni bucket contiene un Pair oppure nullptr se è vuoto
        Hash<K> hashFunction; // Funzione di Hash che calcola l'indice in base ad una funzione dichiarata in Hash
        int size; // Numero di coppie nella tabella
        int divisor; // Numero di bucket della tabella; usato per calcolare l'indice con l'hash
    
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

        void insert(Pair<K,T>& pair) override{

            int index = hashFunction(pair.key) % divisor; // Trovo l'indice legato all'hash della chiave

            int start = index; // Uso start per indicare l'indice da cui sono partito, perche se faccio il linear probing ciclerà per tutta la table e potrei causare un loop
            
            while (table[index] != nullptr)
            {
                index = (index + 1) % divisor; // Vado al successivo indice
                if (index == start) // Se sono tornato all'inizio allora è piena
                {
                    std::cout << "TABELLA PIENA" << std::endl;
                    return;
                }
                
            }
            
            // Terminato il while assegno la coppia
            table[index] = new Pair<K,T>(pair); // Creo il nuovo oggetto perche lo sto passando per riferimento, è meglio crearne uno di copia
            size++;

        }


        // FUNZIONE DI STAMPA
        void toString()
        {
            std::cout << "[";

            for (int i = 0; i < divisor; ++i) {
                
                if (table[i] != nullptr)
                    std::cout << "(\"" << table[i]->key << "\"," << table[i]->value << ")";
                else
                    std::cout << "-";
            
                if (i != divisor - 1)
                    std::cout << ",";
            }

            std::cout << "]" << std::endl;           
        }

};


#endif
/* === INTERFACCIA DEL DIZIONARIO ===
   Questo file definisce l'interfaccia astratta di un dizionario, ovvero una
   struttura dati basata su coppie (chiave, valore). 
   Le classi che la erediteranno dovranno implementare tutte le operazioni
   fondamentali: inserimento, ricerca, modifica ed eliminazione.
   L'interfaccia verrà poi usata per realizzare una HashTable.
*/

#ifndef DICTIONARY_H
#define DICTIONARY_H

/* === CLASSE PAIR ===
* Rappresenta una coppia (Key, Value)
* La chiave serve per identificare l'elemento
* Value è il valore associato ( Ciò che vogliamo memorizzare) alla chiave
*/
template<class K, class T>
class Pair{
    public:
        K key;
        T value;

        Pair() { } // Costruttore di default

        // Costruttore
        Pair(const K& k, const T& e){
            key = k;
            value = e;
        }

        // Costruttore di copia
        Pair(const Pair& p){
            key = p.key;
            value = p.value;
        }
    
};


template <class K, class T>
class Dictionary
{

public:

    // Distruttore
    virtual ~Dictionary() {};

    /* === FUNZIONI SCRITTURA === */
    // Inserisce la coppia nel dizionario
    virtual void insert(Pair<K,T>& pair) = 0;

    // Modifica un valore associato alla chiave nel dizionario
//    virtual void modify(const K& key, const T& e) = 0;
//
//    // Cancella un coppia alla chiave K
//    virtual void erase(const K& k) = 0;
//
//    /* === FUNZIONI DI SERVIZIO === */
//
//    // Ritorna una coppia alla chiave k
//    virtual Pair<K,T>* find(const K& k) const = 0;
//
//    // Ritorna il numero di coppie nel dizionario
//    virtual int size() const = 0;
    

};

#endif

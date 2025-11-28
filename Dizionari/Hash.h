/*
 * Questo file definisce un template di classe Hash, utilizzato per calcolare
 * il valore hash di oggetti di tipo generico K. 
 *
 * La funzione hash converte una chiave K in un indice numerico (size_t),
 * utile per accedere a una tabella hash.
 *
 * size_t è un tipo intero senza segno, garantito abbastanza grande per contenere
 * l'indirizzo massimo di memoria, quindi è sicuro per indici di array.
 *
 * static_cast<size_t>(...) serve a convertire in modo esplicito un tipo (qui int)
 * in size_t, evitando warning o errori di compilazione per differenze di tipo.
 */

#ifndef HASH_H
#define HASH_H

#include <iostream>

// Classe Astratta
template<class K>
class Hash{
    public:
        size_t operator()(const K k) const;
};

template <>
class Hash<int>{
    public:
        size_t operator()(const int the_key) const{
            // Converte l'intero in size_t per ottenere un indice valido per la HashTable
            return static_cast<size_t>(the_key);
        }
};

// TODO: Specializzazione per la string


#endif
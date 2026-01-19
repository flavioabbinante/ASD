/* ============================================================
 * LISTA (Astrazione Lista)
 *
 * ============================================================ */

#ifndef LIST_H
#define LIST_H

template <class T>
class List {
public:

    // Distruttore 
    virtual ~List() {}

    /* === FUNZIONI DI CONTROLLO === */
    // Verifica se la lista è vuota
    virtual bool isEmpty() const = 0;
    
    // Restituisce la dimensione della lista
    virtual int size() const = 0;

    /* === FUNZIONI DI INSERIMENTO === */
    // Inserisce un elemento all'inizio
    virtual void pushFront(T e) = 0;
    // Inserisce un elemento alla fine
    virtual void pushBack(T e) = 0;
    // Inserisce un elemento in una posizione specifica
    virtual void insertAt(int index, T e) = 0;

    /* === FUNZIONI DI CANCELLAZIONE === */
    // Rimuove il primo elemento
    virtual void removeFront() = 0;
    // Rimuove l'ultimo elemento
    virtual void removeBack() = 0;
    // Rimuove l'elemento a un indice specifico
    virtual void removeAt(int index) = 0;

    /* === FUNZIONI DI ACCESSO E MODIFICA === */
    // Legge il valore a un determinato indice
    virtual T getAt(int index) = 0;
    // Cambia il valore a un determinato indice
    virtual void changeAt(T e, int index) = 0;
    // Cerca un elemento e ne restituisce la posizione
    virtual int searchElement(T e) = 0;

    /* === FUNZIONI DI UTILITÀ === */
    // Rappresentazione testuale della lista
    virtual void toString() const = 0;
};

#endif // LIST_H
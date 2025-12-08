/**
 * 
 * Interfaccia per l'uso di un ALBERO N-ARIO con i principali metodi 
 * Di creazione visita inserimento e cancellazione 
 * 
 */

#ifndef N_TREE_H
#define N_TREE_H


// T: tipo di dato da inserire (char, int, string)
// NodeType: Tipo di nodo dell'albero (int per array, ListNode per liste)

template <class DataType, class NodeType>
class NaryTree {
public:
    
    // Distruttore virtuale
    virtual ~NaryTree() = default;


    /** =============================
     *            GETTERS
     *  ============================= */

    // Ritorna la radice
    virtual NodeType getRoot() const = 0;
    // Ritorna il primo figlio della root
    virtual NodeType getFirstChild(NodeType root) const = 0;
    // Ritorna l'ultimo fratello 
    virtual NodeType getNextSibling(NodeType node) const = 0;
    // Ritorna il genitore del figlio passato
    virtual NodeType getParent(NodeType child) const = 0;
    // Ritorna il valore di un noto
    virtual DataType getValue(NodeType node) const = 0;


    /** =============================
     *            INSERIMENTO
     *  ============================= */

    // Inserimento alla radice
    virtual void setRoot(DataType value) = 0;

    // Inserimento di un figlio partendo dalla radice ( o radice del sotto-albero)
    virtual void insertChild(NodeType root,DataType value) = 0;

    // Inserimento di un fratello
    virtual void insertSibiling(NodeType prevSibling, DataType value) = 0;


    // === MODIFICA ===
    // Sovrascrive il valore di un nodo
    virtual void write(NodeType node , DataType newVal) = 0;


    // === CANCELLAZIONE ===
    // Cancella un nodo
    virtual void erase(NodeType node) = 0;

    virtual void eraseSubtree(NodeType subTreeRoot) = 0;

    // === Funzioni di controllo ===

    // Controlla se la root è vuota
    virtual bool isEmpty() const = 0;

    // Controlla se il nodo corrente è una foglia
    virtual bool isLeaf(NodeType node) const = 0;
    
    // Controlla se è l'ultimo fratello
    virtual bool isLastSibling(NodeType node) const = 0;


    // Metodi di ATTRAVERSAMENTO

    virtual void preOrder(NodeType) const = 0; // R S D
    virtual void inOrder(NodeType) const = 0; // D R S
    virtual void postOrder(NodeType) const = 0; // S D R

    // Breath First Search
    virtual void bfs(NodeType) const = 0;

};

#endif
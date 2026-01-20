/**
 * Interfaccia per la realizzazione di un grafo
 * Con le funzioni principali da sovrascrivere
 */

#ifndef GRAFO_H
#define GRAFO_H

#include "../LinkedList/LinkedList.h"

/**
 * Classe Arco:
 * Rappresenta un arco di un grafo, cioè un collegamento tra due nodi.
 *
 * N: tipo dei nodi collegati dall'arco
 * P: tipo del P associato all'arco
 */
template <class N,class P>
class Arco {

    public:
    N n1; // N 1
    N n2; // N 2
    P peso; // P del cammino di quell'arco

};

/**
 * Classe Grafo
 * Interfaccia astratta per la rappresentazione di un grafo generico.
 *
 * E: tipo dell'E associata ai nodi ( Contenuto informativo )
 * P: tipo del P associato agli archi
 * N: tipo dei nodi del grafo
 */
template<class E, class P, class N>
class Grafo{

    public:

        // --- Getters ---
        // Controlla se il grafo è vuoto
        virtual bool isEmpty() const = 0; 

        // Restituisce il numero di nodi
        virtual int getNumNodes() const = 0; 

        // Restituisce il numero di archi
        virtual int getNumEdges() const = 0; 

        // Restituisce tutti i nodi
        virtual LinkedList<N> getNodes() const = 0; 

        // Restituisce i nodi adiacenti
        virtual LinkedList<N*> getAdjacentNodes(N node) const = 0; 

        // Restituisce il valore del nodo corrente
        virtual E getNodeLabel(N node) const = 0; 

        // Restituisce il peso dell'arco
        virtual P getEdgeWeight(N node1, N node2) const = 0; 

        // --- Setters ---
        // Imposta il valore dell'etichetta
        virtual void setNodeLabel(N node, E label) = 0; 

        // Imposta il peso dell'arco
        virtual void setEdgeWeight(N node1, N node2, P weight) = 0; 

        // --- Modifica struttura ---
        // Inserisce un Nodo
        virtual void insertNode(N& node, E label = E()) = 0; 

        // Rimuove un Nodo
        virtual void removeNode(N node) = 0; 

        // Inserisce un arco
        virtual void insertEdge(N from, N to, P weight) = 0; 
        
        // Rimuove un arco
        virtual void removeEdge(N node1, N node2) = 0; 
//
//
        // --- Utility / opzionali ---
//        virtual bool existsNode(N node) const = 0;
//        virtual bool existsEdge(N node1, N node2) const = 0;
//
//        // --- Distruttore ---
//        virtual ~Grafo() {};



};

#endif
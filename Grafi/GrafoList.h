/**
 * GrafoList.h
 * Implementazione concreta di un grafo tramite lista di adiacenza.
 *
 * Nodo: tipo del nodo
 * Peso: tipo del peso sugli archi
 * Etichetta: tipo dell'informazione associata a ciascun nodo
 *
 * La classe implementa tutte le funzioni dell'interfaccia Grafo,
 * sfruttando LinkedList per memorizzare i nodi adiacenti.
 */


#ifndef GRAFO_LIST_H
#define GRAFO_LIST_H

#include "Grafo.h"
#include <iostream>

/** GraphNode
 * 
 * Rappresenta l'identità di un nodo nel grafo tramite un ID.
 * Contiene costruttori, getter e setter per accedere o modificare l'ID.
 */
class GraphNode{
    private:
        int nodoId;
    
    public:
    // Costruttori
        GraphNode(int i){
            nodoId = i;
        };

        GraphNode(){

        };
    // Getter e setter

        int getGraphNodeId(){
            return nodoId;
        };

        void setGraphNodeId(int val){
            nodoId = val;
        };

};


/** InfoArco
 * 
 * Rappresenta un arco uscente da un nodo del grafo.
 * Contiene il peso dell'arco e il nodo di destinazione (to).
 */
template <class P>
class InfoArco{
    public:
    P peso;
    GraphNode to; // Nodo di destinazione
};


/** InfoNodo
 * 
 * Contiene le informazioni associate a un nodo del grafo.
 * Include l'etichetta del nodo, un flag per indicare se è utilizzato,
 * e una lista degli archi uscenti verso altri nodi.
 */
template<class E, class P> 
class InfoNodo{
    public:
        E etichetta; // Contenuto informativo associato al nodo
        bool vuoto; // Indica se il nodo è occupato o libero
        LinkedList<InfoArco<P>> archi; // Lista degli archi uscenti dal nodo

        InfoNodo(){ 
            vuoto = true; 
        }
};


/** GraphList
 * 
 * Implementazione concreta di un grafo tramite lista di adiacenza.
 * 
 * E: tipo dell'etichetta associata ai nodi
 * P: tipo del peso degli archi
 * Utilizza GraphNode per identificare i nodi e LinkedList<InfoArco<P>> per memorizzare gli archi uscenti.
 */
template<class E, class P>
class GraphList: public Grafo<E,P,GraphNode>{
    private:
        int nNodi; // Numero di nodi
        int nArchi; // Numero di archi
        int maxNodi; // Numero totale di nodi
        InfoNodo<E,P>* nodi; // Nodi

    public:

        // === Costruttore e distruttore ===

        // Costruttore 
        GraphList(int max) {
            nNodi = 0;
            nArchi = 0;
            maxNodi = max;
            nodi = new InfoNodo<E,P>[maxNodi];
        
            // Inizializzazione lista di nodi
            for (int i = 0; i < maxNodi; i++) {
                nodi[i].vuoto = true; // nodo libero
                nodi[i].archi = LinkedList<InfoArco<P>>(); // lista di archi vuota
            }
        }

        // Distruttore
        ~GraphList() {
            delete[] nodi;
        }

        // Getters e controlli base
        bool isEmpty() const override{
            return nodi == nullptr;
        }

        // Numero di nodi
        int getNumNodes() const override{
            return nNodi;
        }

        // Numero di archi
        int getNumEdges() const override{
            return nArchi;
        }

        // Numero totale di nodi
        LinkedList<GraphNode*> getNodes() const override{
            
            LinkedList<GraphNode*> result;

            for (int i = 0; i < maxNodi; i++)
            {
                if (!nodi[i].vuoto)
                {
                    GraphNode* gi = new GraphNode(i);

                    result.pushBack(gi);
                }
                
            }

            return result;
            
        }

        // Nodi adiacenti
        LinkedList<GraphNode*> getAdjacentNodes(GraphNode node) const override{
            LinkedList<GraphNode*> result;
            
            int totArchi = nodi[node.getGraphNodeId()].archi.size();

            for (int i = 0; i < totArchi; i++)
            {
                // Recupero le informazioni dell'arco all'indice i
                InfoArco<P> arco = nodi[node.getGraphNodeId()].archi.getAt(i);

                // Creo il nuovo nodo adiacente 
                GraphNode* adiacente = new GraphNode(arco.to.getGraphNodeId());

                result.pushBack(adiacente);
            }
            
            return result;                        
        }

        // Ritorna l'etichetta del nodo
        E getNodeLabel(GraphNode node) const override{

            E etichetta = E();

            if (!nodi[node.getGraphNodeId()].vuoto)
            {
                etichetta =nodi[node.getGraphNodeId()].etichetta; 
            }
            
            return etichetta;
        }

        P getEdgeWeight(GraphNode from, GraphNode to) const override{
            // id dei nodi
            int idFrom = from.getGraphNodeId();
            int idTo = to.getGraphNodeId();
                
            // Lista degli archi del nodo from
            int numeroArchi = nodi[idFrom].archi.size(); // Numero di archi che devo scorrere
                
            // Scorriamo la lista per trovare l'arco verso to
            for (int i = 0; i < numeroArchi; i++) {

                // oggetto InfoArco all'indice i
                InfoArco<P> arco = nodi[idFrom].archi.getAt(i);
                
                // Se la destinazione dell'arco corrisponde all'ID di to
                if (arco.to.getGraphNodeId() == idTo) {
                    return arco.peso; // Restituiamo il peso trovato
                }
            }
        
            // Se non esiste si ritorna uno vuoto
            return P();            
        }

        // Inserisce un nuovo nodo
        void insertNode(GraphNode& node, E label = E()) override{
            // Scorro l'array di nodi fin quando non trovo una posto libero
            for (int i = 0; i < maxNodi; i++)
            {
                // Se il nodo è vuoto
                if (nodi[i].vuoto)
                {
                    // Allora posso inserire
                    nodi[i].vuoto = false; // Imposto a false in modo da evitare la sovrascrittura
                    nodi[i].etichetta = label; // Etichetta
                    nodi[i].archi = LinkedList<InfoArco<P>>(); // Lista di nodi adiacenti
                    node.setGraphNodeId(i); // Assegno l'indice di inserimento come id del nodo
                    nNodi++; // Incremento il numero di nodi
                    return; // Ho inserito allora esco
                }   
            }            
        }

        // Inserisce un arco
        void insertEdge(GraphNode from, GraphNode to, P weight) override{

            // Creo infoArco
            InfoArco<P> newArco;
            newArco.peso = weight;
            newArco.to = to;

            // Inserisco l'arco nella lista
            nodi[from.getGraphNodeId()].archi.pushFront(newArco);
            
            // Aumenta il numero di archi
            nArchi++;

        }





        void toString() const {
            for (int i = 0; i < maxNodi; i++) {
                if (!nodi[i].vuoto) {
                    // Usiamo l'indice i come identificativo del nodo
                    std::cout << "Nodo " << i << " (Etichetta: " << nodi[i].etichetta << "): ";
                
                    // Accediamo alla lista archi del nodo i
                    // Usiamo il tuo metodo size() per il limite del ciclo
                    int numArchi = nodi[i].archi.size(); 

                    for (int j = 0; j < numArchi; j++) {
                        // Usiamo il tuo metodo getAt(index) per leggere l'arco
                        InfoArco<P> arco = nodi[i].archi.getAt(j); 
                        std::cout << "(Dest: " << arco.to.getGraphNodeId()
                                  << ", Peso: " << arco.peso << ") ";
                    }
                    std::cout << "\n";
                }
            }
        }



    };


#endif

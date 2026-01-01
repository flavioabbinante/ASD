#include "GrafoList.h"
#include <iostream>

int main() {

    // Creazione del grafo con massimo 10 nodi
    GraphList<int, int> g(10);

    GraphNode g1, g2, g3;

    // INSERIMENTO DEI NODI ED ARCHI

    g.insertNode(g1, 5); // ID: 0, Label: 5
    g.insertNode(g2, 10); // ID: 1, Label: 10
    g.insertNode(g3, 15); // ID: 2, Label: 15

    g.insertEdge(g1, g2, 1); // Arco da 0 a 1 con peso 1
    g.insertEdge(g1, g3, 1); // Arco da 0 a 2 con peso 1

    g.toString(); // Stampo il grafo 

    // GETTERS E SETTERS
    std::cout << "\nNodi totali: " << g.getNumNodes() << std::endl; // Atteso: 3
    std::cout << "Archi totali: " << g.getNumEdges() << std::endl; // Atteso: 2

    std::cout << "\nEtichetta vecchia g1: " << g.getNodeLabel(g1) << std::endl; // 5
    g.setNodeLabel(g1, 500); // Cambio etichetta
    std::cout << "Etichetta nuova g1: " << g.getNodeLabel(g1) << " (Atteso 500)" << std::endl; //

    std::cout << "\nPeso vecchio g1->g2: " << g.getEdgeWeight(g1, g2) << std::endl; // 1
    g.setEdgeWeight(g1, g2, 99); // Cambio peso dell'arco
    std::cout << "Peso nuovo g1->g2: " << g.getEdgeWeight(g1, g2) << " (Atteso 99)" << std::endl; //

    // TEST DEI NODI
    std::cout << "\nElenco ID Nodi nel Grafo: ";
    LinkedList<GraphNode> listaNodi = g.getNodes(); 

    for (int i = 0; i < listaNodi.size(); i++) {

        std::cout << listaNodi.getAt(i).getGraphNodeId() << " "; 

    }

    std::cout << std::endl;

    // TEST NODI ADIACENTI
    std::cout << "Nodi adiacenti a g1 (ID " << g1.getGraphNodeId() << "): ";

    LinkedList<GraphNode*> adiacenti = g.getAdjacentNodes(g1); 

    for (int i = 0; i < adiacenti.size(); i++) {
        // Devo dereferenziare il puntatore per usare il getter
        GraphNode* ptr = adiacenti.getAt(i);
        if (ptr != nullptr) {
            std::cout << ptr->getGraphNodeId() << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
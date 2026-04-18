#include <iostream>
using namespace std;

#define V 5

int main() {

    int graph[V][V] = {
        {0, 2, 0, 6, 9},
        {1, 0, 3, 5, 8},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int Parent[V], key[V];
    bool MST[V];

    for (int i = 0; i < V; i++) {
        key[i] = 9999;
        MST[i] = false;
    }

    key[0] = 0;
    Parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {

        int min = 9999, u;

        for (int i = 0; i < V; i++) {
            if (!MST[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        MST[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !MST[v] && graph[u][v] < key[v]) {
                Parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    cout <<"PrimsAlgorithm_Basant_80117739"<<endl;
    cout << "Edge \t Weight\n";

    int totalWeight = 0;   // Added variable

    for (int i = 1; i < V; i++) {
        cout << Parent[i] << " - " << i
             << " \t " << graph[i][Parent[i]] << endl;

        totalWeight += graph[i][Parent[i]];   // Adding weight
    }

    cout << "\nTotal Weight of MST: " << totalWeight << endl;  // Print total

    return 0;
}

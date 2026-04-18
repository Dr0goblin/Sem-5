#include <iostream>
using namespace std;

struct Edge
{
    int u, v, weight;
};

int parent[100];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int u, int v)
{
    int u_set = find(u);
    int v_set = find(v);
    parent[u_set] = v_set;
}

void sortEdges(Edge arr[], int e)
{
    for(int i = 0; i < e - 1; i++)
    {
        for(int j = i + 1; j < e; j++)
        {
            if(arr[i].weight > arr[j].weight)
            {
                Edge temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int v, e;
    cout <<"KruskalAlgorithm_Basant_80117739"<<endl;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;

    Edge arr[e];

    cout << "Enter edge (u v weight):\n";
    for(int i = 0; i < e; i++)
        cin >> arr[i].u >> arr[i].v >> arr[i].weight;

    for(int i = 0; i < v; i++)
        parent[i] = i;

    sortEdges(arr, e);

    int count = 0;
    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for(int i = 0; i < e && count < v - 1; i++)
    {
        int u_set = find(arr[i].u);
        int v_set = find(arr[i].v);

        if(u_set != v_set)
        {
            cout << arr[i].u << " - " << arr[i].v 
                 << " = " << arr[i].weight << endl;
            totalCost += arr[i].weight;
            unionSet(u_set, v_set);
            count++;
        }
    }

    cout << "Total Cost of MST = " << totalCost;

    return 0;
}


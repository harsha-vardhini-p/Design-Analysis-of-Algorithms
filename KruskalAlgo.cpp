#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

struct CompareEdges {
    bool operator()(const Edge& a, const Edge& b) const {
        return a.weight > b.weight;
    }
};

int findSet(int vertex, vector<int>& parent) {
    if (parent[vertex] != vertex) {
        parent[vertex] = findSet(parent[vertex], parent);
    }
    return parent[vertex];
}

void unionSets(int u, int v, vector<int>& parent) {
    int rootU = findSet(u, parent);
    int rootV = findSet(v, parent);

    parent[rootV] = rootU;
}

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    if (V <= 0 || E < 0) {
        cout << "Invalid number of vertices or edges.\n";
        return 0;
    }

    priority_queue<Edge, vector<Edge>, CompareEdges> edges;

    cout << "Enter each edge (u v weight):\n";
    for (int i = 0; i < E; i++) {
        Edge edge;
        cin >> edge.u >> edge.v >> edge.weight;

        if (edge.u < 0 || edge.u >= V ||
            edge.v < 0 || edge.v >= V) {
            cout << "Invalid vertex number. Use 0 to " << V - 1 << ".\n";
            return 0;
        }

        edges.push(edge);
    }

    vector<int> parent(V);
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    vector<Edge> mst;  
    int totalWeight = 0;

    while (!edges.empty() && mst.size() < static_cast<size_t>(V - 1)) {
        Edge edge = edges.top();  
        edges.pop();

        if (findSet(edge.u, parent) != findSet(edge.v, parent)) {
            mst.push_back(edge);
            totalWeight += edge.weight;
            unionSets(edge.u, edge.v, parent);
        }
    }

    if (mst.size() != static_cast<size_t>(V - 1)) {
        cout << "MST does not exist: the graph is disconnected.\n";
        return 0;
    }

    cout << "\nEdges in the MST:\n";
    for (int i = 0; i < static_cast<int>(mst.size()); i++) {
        cout << mst[i].u << " - " << mst[i].v
             << " : " << mst[i].weight << '\n';
    }

    cout << "Total weight = " << totalWeight << '\n';

    return 0;
}

//OUTPUT
/*
Enter number of vertices and edges: 7 6
Enter each edge (u v weight):
0 1 4
0 2 3
1 3 5
2 4 2
4 5 6
5 6 1

Edges in the MST:
5 - 6 : 1
2 - 4 : 2
0 - 2 : 3
0 - 1 : 4
1 - 3 : 5
4 - 5 : 6
Total weight = 21

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Neighbor {
    int vertex;
    int weight;
};

struct HeapEdge {
    int vertex;
    int parent;
    int weight;
};

struct CompareEdges {
    bool operator()(const HeapEdge& a, const HeapEdge& b) const {
        return a.weight > b.weight;
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    if (V <= 0 || E < 0) {
        cout << "Invalid number of vertices or edges.\n";
        return 0;
    }

    vector<vector<Neighbor> > graph(V);

    cout << "Enter each edge (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid vertex number. Use 0 to " << V - 1 << ".\n";
            return 0;
        }

        Neighbor first;
        first.vertex = v;
        first.weight = weight;
        graph[u].push_back(first);

        Neighbor second;
        second.vertex = u;
        second.weight = weight;
        graph[v].push_back(second);
    }

    vector<bool> visited(V, false);
    vector<HeapEdge> mst;
    priority_queue<HeapEdge, vector<HeapEdge>, CompareEdges> pq;

    HeapEdge start;
    start.vertex = 0;
    start.parent = -1;
    start.weight = 0;
    pq.push(start);

    int totalWeight = 0;
    int verticesAdded = 0;

    while (!pq.empty()) {
        HeapEdge current = pq.top();
        pq.pop();

        int u = current.vertex;

        if (visited[u]) {
            continue;
        }

        visited[u] = true;
        verticesAdded++;

        if (current.parent != -1) {
            mst.push_back(current);
            totalWeight += current.weight;
        }

        for (int i = 0; i < static_cast<int>(graph[u].size()); i++) {
            int v = graph[u][i].vertex;

            if (!visited[v]) {
                HeapEdge next;
                next.vertex = v;
                next.parent = u;
                next.weight = graph[u][i].weight;
                pq.push(next);
            }
        }
    }

    if (verticesAdded != V) {
        cout << "MST does not exist: the graph is disconnected.\n";
        return 0;
    }

    cout << "\nEdges in the MST:\n";
    for (int i = 0; i < static_cast<int>(mst.size()); i++) {
        cout << mst[i].parent << " - " << mst[i].vertex
             << " : " << mst[i].weight << '\n';
    }

    cout << "Total weight = " << totalWeight << '\n';

    return 0;
}

//OUTPUT:

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
0 - 2 : 3
2 - 4 : 2
0 - 1 : 4
1 - 3 : 5
4 - 5 : 6
5 - 6 : 1
Total weight = 21
*/
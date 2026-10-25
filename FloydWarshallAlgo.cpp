#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    const long long INF = (1LL << 60);

    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<long long>> dist(n, vector<long long>(n));

    cout << "Enter the adjacency matrix:\n";
    cout << "(Use -1 for no edge and 0 on the diagonal)\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long weight;
            cin >> weight;

            if (i == j)
                dist[i][j] = 0;
            else if (weight == -1)
                dist[i][j] = INF;
            else
                dist[i][j] = weight;
        }
    }

    // Try each vertex k as an intermediate vertex.
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    long long newDistance = dist[i][k] + dist[k][j];

                    if (newDistance < dist[i][j])
                        dist[i][j] = newDistance;
                }
            }
        }
    }

    // A negative diagonal value indicates a negative-weight cycle.
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            cout << "\nGraph contains a negative-weight cycle.\n";
            return 0;
        }
    }

    cout << "\nShortest distance matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}
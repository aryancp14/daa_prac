#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

void printMatrix(int dist[4][4], int V) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "-------------------------" << endl;
}

void floydWarshall(int graph[4][4], int V) {
    int dist[4][4];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    cout << "Initial distance matrix:\n";
    printMatrix(dist, V);

    for (int k = 0; k < V; k++) {
        cout << "Using vertex " << k + 1 << " as an intermediate node:\n";

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
              if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        printMatrix(dist, V);
    }

    cout << "Final shortest distances between every pair of vertices:\n";
    printMatrix(dist, V);
}

int main() {
    int V = 4;

    int graph[4][4] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    floydWarshall(graph, V);

    return 0;
}

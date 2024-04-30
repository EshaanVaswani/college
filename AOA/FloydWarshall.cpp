#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

void printMatrices(const vector<vector<int>>& dist, const vector<vector<int>>& next, int V) {
    cout << "Distance Matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << setw(5) << "INF";
            else
                cout << setw(5) << dist[i][j];
        }
        cout << endl;
    }

    cout << "\nPredecessor Matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i==j || next[i][j] == -1)
                cout << setw(5) << "NIL";
            else
                cout << setw(5) << next[i][j];
        }
        cout << endl;
    }
}

void printPath(const vector<vector<int>>& next, int u, int v) {
    if (next[u][v] == -1) {
        cout << "No path exists";
        return;
    }
    cout << u;
    while (u != v) {
        u = next[u][v];
        cout << " -> " << u;
    }
}

void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist(V, vector<int>(V, INF));
    vector<vector<int>> next(V, vector<int>(V, -1));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != INF && i != j)
                next[i][j] = j;
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][i] = next[i][k];
                }
            }
        }
    }

    printMatrices(dist, next, V);

    cout << "\nAll pairs shortest paths:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << "Shortest path from " << i << " to " << j << ": ";
            printPath(next, i, j);
            cout << endl;
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        { 0, 5, INF, 10 },
        { INF, 0, 3, INF },
        { INF, INF, 0, 1 },
        { INF, INF, INF, 0 }
    };

    int V = graph.size();

    floydWarshall(graph, V);

    return 0;
}

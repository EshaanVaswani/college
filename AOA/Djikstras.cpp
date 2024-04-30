#include<bits/stdc++.h>
using namespace std;

const int V = 9;

int minDistance(const vector<int>& dist, const vector<bool>& sptSet) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printDandPi(const vector<int>& dist, const vector<int>& predecessor) {
    cout << "Vertex\tDistance from Source\tPredecessor" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << dist[i] << "\t\t\t" << predecessor[i] << endl;
    }
}

void printPath(const vector<int>& pi, int v, int src) {
    if (v == src)
        cout << v;
    else if (pi[v] == -1)
        cout << "No path exists";
    else {
        printPath(pi, pi[v], src);
        cout << " -> " << v;
    }
}

void dijkstra(const vector<vector<int>>& graph, int src) {
    vector<int> dist(V, INT_MAX);
    vector<bool> sptSet(V, false);
    vector<int> predecessor(V, -1);

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                predecessor[v] = u;
            }
        }
    }

    printDandPi(dist, predecessor);

    cout << "\nShortest Paths from Source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Path to vertex " << i << ": ";
        printPath(predecessor, i, src);
        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);

    return 0;
}

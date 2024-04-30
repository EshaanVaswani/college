#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V,E;
    vector<Edge> edges;

    Graph(int V, int E): V(V), E(E), edges(E) {}
};

void printPath(vector<int>& pi, int v, int u){
    if(u==v){
        cout << v;
    } else if(pi[u] == -1) {
        cout << "No path exists between " << v << " and " << u << endl;
    } else {
        printPath(pi, v, pi[u]);
        cout << " -> " << u ;
    }
}

void printMatrices(vector<int>& d, vector<int>& pi, int V){
    cout << "Vertex\t\tD\t\tPi\n";
    for(int i=0; i<V; i++){
        cout << i << "\t\t" << d[i] << "\t\t" << pi[i] << endl;
    }
}

void bellmanFord(Graph& graph, int source){
    int V = graph.V;
    int E = graph.E;

    vector<int> d(V,INT_MAX);
    vector<int> pi(V,-1);

    d[source] = 0;

    for(int i=0; i<V-1; i++){
        for(int j=0; j<E; j++){
            int u = graph.edges[j].src;
            int v = graph.edges[j].dest;
            int w = graph.edges[j].weight;

            if(d[u] != INT_MAX && d[u] + w < d[v]){
                d[v] = d[u] + w;
                pi[v] = u;
            }
        }
    }

    for(int j=0; j<E; j++){
        int u = graph.edges[j].src;
        int v = graph.edges[j].dest;
        int w = graph.edges[j].weight;

        if(d[u] != INT_MAX && d[u] + w < d[v]){
            cout << "Graph contains negative weight cycle";
            return;
        }
    }

    printMatrices(d,pi,V);

    cout << "Shortest paths: \n";
    for(int i=0; i<V; i++){
        cout << source << "->" << i << ": ";
        printPath(pi, source, i);
        cout << endl;
    }
}

int main() {
    int V = 5;
    int E = 8;

    Graph graph(V, E);

    graph.edges = {
        {4,1,4}, {4,3,2}, {3,1,1}, {1,0,3},
        {0,2,6}, {0,3,3}, {3,2,1}, {2,3,2}
    };

    int source = 4;

    bellmanFord(graph, source);

    return 0;
}

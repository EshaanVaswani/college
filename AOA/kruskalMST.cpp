#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;
};

struct DisjointSets {
    vector<int> parent, rank;

    DisjointSets(int n): parent(n), rank(n,1){
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int find(int u){
        if(u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);

        if(rootX != rootY){
            if(rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else if(rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

bool comp(const Edge& a, const Edge& b){
    return a.weight < b.weight;
}

void kruskalMST(Graph& graph){
    vector<Edge> result;
    sort(graph.edges.begin(), graph.edges.end(), comp);

    DisjointSets ds(graph.V);

    for(auto& e: graph.edges){
        int x = ds.find(e.src);
        int y = ds.find(e.dest);

        if(x!=y){
            result.push_back(e);
            ds.unionSet(x,y);
            if(result.size() == graph.V-1) break;
        }
    }

    int cost = 0;
    cout << "Edge \tWeight\n";
    for(auto& e: result){
        cout << e.src << "-" << e.dest << "\t" << e.weight << endl;
        cost += e.weight;
    }

    cout << "Minimum Cost = " << cost;
}

int main(){
    Graph graph = {4, 5,
        {{0, 1, 10},
         {0, 2, 6},
         {0, 3, 5},
         {1, 3, 15},
         {2, 3, 4}
    }};

    kruskalMST(graph);

    return 0;
}

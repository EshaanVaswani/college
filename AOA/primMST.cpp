#include<bits/stdc++.h>
using namespace std;

void printMST(vector<int>& parent, vector<vector<int>>& graph){
    int cost = 0;
    cout << "Edge \tWeight\n";
    for(int i=1; i<graph.size(); i++){
        cout << parent[i] << "-" << i << "\t" << graph[i][parent[i]] << endl;
        cost += graph[i][parent[i]];
    }

    cout << "Minimum Cost = " << cost;
}

int minKey(vector<int>& key, vector<bool>& mstSet){
    int min=INT_MAX;
    int i;

    for(int v=0; v<key.size(); v++){
        if(!mstSet[v] && key[v] < min){
            min = key[v];
            i=v;
        }
    }

    return i;
}

void primMST(vector<vector<int>>& graph){
    int V = graph.size();

    vector<int> parent(V);
    vector<int> key(V,INT_MAX);
    vector<bool> mstSet(V,false);

    key[0] = 0;
    parent[0] = -1;

    for(int i=0; i<V-1; i++){
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for(int v=0; v<V; v++){
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]){
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printMST(parent, graph);
}

int main(){
    vector<vector<int>> graph = {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0},
    };

    primMST(graph);

    return 0;
}

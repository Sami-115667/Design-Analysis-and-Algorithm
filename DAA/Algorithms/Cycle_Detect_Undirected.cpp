#include <bits/stdc++.h>
using namespace std;

bool Cycle(int u, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            if (Cycle(v, u, adj, visited)) { 
                return true;
            }
        } else if (v != parent) {
            return true;
        }
    }

    return false;
}



int main(){
  
    int V, E;
    
    cin >> V >> E;

    vector<vector<int>> adj(V);

    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    vector<bool> visited(V, false);
    bool CycleExists = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (Cycle(i, -1, adj, visited)) {
                CycleExists = true;
                break;
            }
        }
    }
    

    if (CycleExists) {
        cout << "Cycle is present\n";
    } else {
        cout << "Cycle is not present\n";
    }

  
}
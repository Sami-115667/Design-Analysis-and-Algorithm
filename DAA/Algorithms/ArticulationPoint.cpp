#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void DFS(int u, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<bool>& ap) {
    static int time = 0;
    int children = 0;

    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            parent[v] = u;
            DFS(v, adj, visited, disc, low, parent, ap);

            low[u] = min(low[u], low[v]);

            if (parent[u] == -1 && children > 1)
                ap[u] = true;

            if (parent[u] != -1 && low[v] >= disc[u])
                ap[u] = true;
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findArticulationPoints(const vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    vector<int> disc(V, 0);
    vector<int> low(V, 0);
    vector<int> parent(V, -1);
    vector<bool> ap(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, adj, visited, disc, low, parent, ap);
        }
    }

    cout << "Articulation Points: ";
    for (int i = 0; i < V; i++) {
        if (ap[i])
            cout << i << " ";
    }
    cout << endl;
}

int main() {
    int V, edge;
    cin >> V >> edge;

    vector<vector<int>> adj(V);

    int x, y;
    for (int i = 0; i < edge; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << "Articulation Points in the graph:\n";
    findArticulationPoints(adj, V);

    return 0;
}

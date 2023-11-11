#include <bits/stdc++.h>
using  namespace std;


const int MAXN = 10000; 
int n, m; 
std::vector<int> adj[MAXN]; 
bool visited[MAXN];
int disc[MAXN]; 
int low[MAXN]; 
int parent[MAXN];
std::vector<std::pair<int, int>> bridges;

void dfs(int u, int time) {
    visited[u] = true;
    disc[u] = low[u] = time;
    time++;

    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v, time);

            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u]) {
                bridges.push_back({u, v});
            }
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findBridges() {
    for (int i = 0; i <n ; i++) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }
}

int main() {
   
    cin >> n >> m;

   
    for (int i = m-1; i >= 0; i--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findBridges();

    sort(bridges.begin(),bridges.end());

    cout << "Bridges in the graph:" << endl;
    for (const auto& bridge : bridges) {
        cout << bridge.first << "  " << bridge.second << endl;
    }

    return 0;
}

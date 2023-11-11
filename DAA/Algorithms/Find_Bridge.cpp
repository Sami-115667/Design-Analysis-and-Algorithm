#include <iostream>
#include <vector>
#include <algorithm>

const int MAXN = 10000; // Maximum number of vertices

int n, m; // Number of vertices and edges
std::vector<int> adj[MAXN]; // Adjacency list
bool visited[MAXN];
int disc[MAXN]; // Discovery time for each vertex
int low[MAXN]; // Lowest discovery time reachable from each vertex
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

            low[u] = std::min(low[u], low[v]);

            if (low[v] > disc[u]) {
                bridges.push_back({u, v});
            }
        } else if (v != parent[u]) {
            low[u] = std::min(low[u], disc[v]);
        }
    }
}

void findBridges() {
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }
}

int main() {
    // Read input: n (number of vertices) and m (number of edges)
    std::cin >> n >> m;

    // Read edges
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findBridges();

    std::cout << "Bridges in the graph:" << std::endl;
    for (const auto& bridge : bridges) {
        std::cout << bridge.first << " - " << bridge.second << std::endl;
    }

    return 0;
}

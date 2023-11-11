#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m; // Number of nodes and edges
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n); // Adjacency list
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<int> key(n, INF); // Key values to track minimum weight edge
    vector<bool> visited(n, false); // To mark visited nodes
    vector<int> parent(n, -1); // To track the minimum spanning tree

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min heap

    int start_node = 0; // Starting node for MST
    pq.push(make_pair(0, start_node));
    key[start_node] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }


    for (int i = 1; i < n; ++i) {
        cout << parent[i] << " - " << i << "\n";
    }

    // Calculate and print the total cost of the Minimum Spanning Tree
    int totalCost = 0;
    for (int i = 1; i < n; ++i) {
        totalCost += key[i];
    }
    cout << "Total Cost of Minimum Spanning Tree: " << totalCost << "\n";

    return 0;
}

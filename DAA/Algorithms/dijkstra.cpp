#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // Infinity

vector<vector<pair<int, int>>> graph; // Adjacency list: {destination, weight}

vector<int> dijkstra(int source, int n) {
    vector<int> distance(n, INF);
    distance[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > distance[u])
            continue;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

int main() {
    int n, m; // Number of nodes and edges
    cin >> n >> m;

    graph.resize(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w; // Edge from u to v with weight w
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int source; // Source node
    cin >> source;

    vector<int> distances = dijkstra(source, n);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": " << distances[i] << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18; // Infinity

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < M; ++i) {
        int U, V, W;
        cin >> U >> V >> W;
        adj[U].emplace_back(V, W);
        adj[V].emplace_back(U, W); // For undirected graph
    }

    vector<long long> dist(N, INF);
    vector<int> prev(N, -1);

    dist[0] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[1] == INF) {
        cout << "NOT REACHABLE" << endl;
    } else {
        vector<int> path;
        for (int u = 1; u != -1; u = prev[u]) {
            path.push_back(u);
        }
        reverse(path.begin(), path.end());

        for (int u : path) {
            cout << u << endl;
        }
    }

    return 0;
}

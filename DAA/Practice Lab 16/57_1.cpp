#include <bits/stdc++.h>

using namespace std;

const long long INF = numeric_limits<long long>::max();

void addEdge(vector<vector<pair<int, int>>>& adj, int u, int v, int w) {
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w); // For undirected graph
}

vector<long long> shortestPathsFromSource(int source, int V, const vector<vector<pair<int, int>>>& adj) {
    vector<long long> dist(V, INF);
    dist[source] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        long long uDist = pq.top().first;
        pq.pop();

        if (uDist > dist[u])
            continue;

        for (auto neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N);

    for (int i = 0; i < M; ++i) {
        int U, V, W;
        cin >> U >> V >> W;
        addEdge(adj, U, V, W);
    }

    vector<long long> shortestPaths = shortestPathsFromSource(0, N, adj);

    for (int i = 0; i < N; ++i) {
        cout << i << ": ";
        if (shortestPaths[i] == INF) {
            cout << "-1";
        } else {
            cout << shortestPaths[i];
        }
        cout << endl;
    }

    return 0;
}

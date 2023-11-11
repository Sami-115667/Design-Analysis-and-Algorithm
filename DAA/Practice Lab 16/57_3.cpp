#include <bits/stdc++.h>


using namespace std;

const int INF = 1e9;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
    }

    vector<int> shortestDistancesFromSource(int source) {
        vector<int> dist(V, INF);
        dist[source] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            int uDist = pq.top().first;
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
};

int main() {
    int N, M;
    cin >> N >> M;

    Graph g(N);

    for (int i = 0; i < M; ++i) {
        int U, V, W;
        cin >> U >> V >> W;
        g.addEdge(U, V, W);
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int X, Y;
        cin >> X >> Y;

        vector<int> shortestDistances = g.shortestDistancesFromSource(X);

        if (shortestDistances[Y] == INF) {
            cout << "Impossible" << endl;
        } else if (shortestDistances[Y] == -INF) {
            cout << "-Infinity" << endl;
        } else {
            cout << shortestDistances[Y] << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>


using namespace std;

const int INF = 1e9;
const int NIL = 0;

vector<vector<int>> adj; // Adjacency list representation of the bipartite graph
vector<int> dist, pairU, pairV;

bool bfs(int n) {
    queue<int> q;
    dist.assign(n + 1, INF);

    for (int u = 1; u <= n; ++u) {
        if (pairU[u] == NIL) {
            dist[u] = 0;
            q.push(u);
        }
    }

    dist[NIL] = INF;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist[u] < dist[NIL]) {
            for (int v : adj[u]) {
                if (dist[pairV[v]] == INF) {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
    }

    return (dist[NIL] != INF);
}

bool dfs(int u) {
    if (u != NIL) {
        for (int v : adj[u]) {
            if (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v])) {
                pairV[v] = u;
                pairU[u] = v;
                return true;
            }
        }

        dist[u] = INF;
        return false;
    }

    return true;
}

int hopcroftKarp(int n, int m) {
    pairU.assign(n + 1, NIL);
    pairV.assign(m + 1, NIL);

    int matching = 0;

    while (bfs(n)) {
        for (int u = 1; u <= n; ++u) {
            if (pairU[u] == NIL && dfs(u)) {
                ++matching;
            }
        }
    }

    return matching;
}

int main() {
    int n, m;

    cout << "Enter the number of vertices in the first partition: ";
    cin >> n;

    cout << "Enter the number of vertices in the second partition: ";
    cin >> m;

    // Initialize the adjacency list (edges of the bipartite graph)
    adj.resize(n + 1);

    cout << "Enter the edges of the bipartite graph (e.g., u v):" << endl;

    int u, v;
    while (cin >> u >> v) {
        adj[u].push_back(v);
    }

    int maxMatching = hopcroftKarp(n, m);

    cout << "Maximum cardinality matching: " << maxMatching << endl;

    return 0;
}

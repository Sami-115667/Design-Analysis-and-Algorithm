#include <bits/stdc++.h>
using namespace std;

const int N = 505, INF = 1e9 + 7;
vector<pair<int, int>> adj[N];
int dis[N][N];
int n, m;
vector<vector<int>> edges;

vector<int> bellmanFord() {
    int newVertex = 0;
    for (int i = 1; i <= n; i++) {
        edges.push_back({newVertex, i, 0});
    }

    vector<int> d(n + 1, INF);
    int startingNode = 0;
    d[startingNode] = 0;

    for (int i = 1; i < n; i++) {
        bool any = true;
        for (auto e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                any = false;
            }
        }

        if (any)
            break;
    }

    return d;
}

void dijkstra(int source) {
    set<pair<int, int>> pq;
    vector<bool> vis(n + 1, false);
    dis[source][source] = 0;
    pq.insert({0, source});

    while (!pq.empty()) {
        auto front = *pq.begin();
        int nod = front.second;
        int edg = front.first;
        pq.erase(pq.begin());

        if (!vis[nod]) {
            vis[nod] = true;
            for (auto e : adj[nod]) {
                int child = e.first;
                int weight = e.second;
                if (dis[source][child] > dis[source][nod] + weight) {
                    dis[source][child] = dis[source][nod] + weight;
                    pq.insert({dis[source][nod], child});
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<int> c = bellmanFord();

    for (auto &e : edges) {
        int u = e[0], v = e[1];
        e[2] += c[u] - c[v];
    }

    for (auto e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                dis[i][j] = INF;

    for (int i = 1; i <= n; i++)
        dijkstra(i);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] == INF)
                cout << "INF" << ' ';
            else
                cout << dis[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

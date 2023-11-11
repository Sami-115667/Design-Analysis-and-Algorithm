#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

void floyd_warshall(vector<vector<int>>& dist) {
    int n = dist.size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {
        graph[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = graph[v][u] = w;
    }

    floyd_warshall(graph);

    for (int step = 1; step < n; ++step) {
        long long total_cost = 0;
        for (int i = 1; i < step; ++i) {
            for (int j = i + 1; j <= step; ++j) {
                total_cost += graph[i][j];
            }
        }
        cout << total_cost << endl;
    }

    return 0;
}

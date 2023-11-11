#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
vector<int> parent(N);
vector<int> size(N);

void make(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_pathcompression(int v) {
    if (v == parent[v]) // time complexity O(logN)
        return v;
    return parent[v] = find_pathcompression(parent[v]);
}

void Union_rank(int a, int b) {
    int a1 = find_pathcompression(a);
    int a2 = find_pathcompression(b);
    if (a1 != a2) {
        if (size[a1] < size[a2]) {
            swap(a1, a2);
        }
        parent[a2] = a1;
        size[a1] += size[a2];
    }
}

int main() {
    for (int i = 0; i < N; i++) {  // Corrected loop initialization
        make(i);
    }

    int node, edge;
    cin >> node >> edge;

    vector<vector<int>> adj;

    for (int i = 0; i < edge; i++) {
        int w, u, v;
        cin >> u >> v >> w;
        adj.push_back({w, u, v});
    }
    sort(adj.begin(), adj.end());
    int cost = 0;

    for (auto i : adj) {
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = find_pathcompression(u);
        int y = find_pathcompression(v);
        if (x == y) {
            continue;
        } else {
            cout << u << " " << v << endl;
            cost += w;
            Union_rank(u, v);
        }
    }

    cout << cost << endl;

    return 0;
}

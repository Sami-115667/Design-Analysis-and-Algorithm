#include <iostream>
#include <vector>

const int MAXN = 10000; // Maximum number of vertices

int n, m; // Number of vertices and edges
std::vector<int> adj[MAXN]; // Adjacency list
int degree[MAXN]; // Degree of each vertex

bool hasEulerianPath() {
    int oddDegreeCount = 0;
    for (int i = 0; i < n; ++i) {
        if (degree[i] % 2 != 0) {
            oddDegreeCount++;
        }
    }
    return (oddDegreeCount == 0 || oddDegreeCount == 2);
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
        degree[u]++;
        degree[v]++;
    }

    if (hasEulerianPath()) {
        std::cout << "The graph has an Eulerian path." << std::endl;
    } else {
        std::cout << "The graph does not have an Eulerian path." << std::endl;
    }

    return 0;
}

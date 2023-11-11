#include <iostream>
#include <vector>

const int MAXN = 10000; // Maximum number of vertices

int n, m; // Number of vertices and edges
std::vector<int> adj[MAXN]; // Adjacency list
int degree[MAXN]; // Degree of each vertex

bool isConnected() {
    std::vector<bool> visited(n, false);
    int start = -1;

    for (int i = 0; i < n; ++i) {
        if (degree[i] > 0) {
            start = i;
            break;
        }
    }

    if (start == -1) {
        return true; // An empty graph is considered connected
    }

    std::vector<int> stack;
    stack.push_back(start);

    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();

        if (!visited[u]) {
            visited[u] = true;
            for (int v : adj[u]) {
                stack.push_back(v);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i] && degree[i] > 0) {
            return false;
        }
    }

    return true;
}

bool hasEulerianCircuit() {
    if (!isConnected()) {
        return false;
    }

    for (int i = 0; i < n; ++i) {
        if (degree[i] % 2 != 0) {
            return false;
        }
    }
    return true;
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

    if (hasEulerianCircuit()) {
        std::cout << "The graph has an Eulerian circuit." << std::endl;
    } else {
        std::cout << "The graph does not have an Eulerian circuit." << std::endl;
    }

    return 0;
}

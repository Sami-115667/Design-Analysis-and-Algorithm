#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 1e9;

// Function to find the maximum flow in the graph using Ford-Fulkerson algorithm
int fordFulkerson(vector<vector<int>>& graph, int source, int sink) {
    int n = graph.size();
    vector<vector<int>> residualGraph(n, vector<int>(n, 0));

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            residualGraph[u][v] = graph[u][v];
        }
    }

    vector<int> parent(n);
    int maxFlow = 0;

    while (true) {
        fill(parent.begin(), parent.end(), -1);

        queue<pair<int, int>> q;
        q.push({source, INF});

        while (!q.empty()) {
            int u = q.front().first;
            int capacity = q.front().second;
            q.pop();

            for (int v = 0; v < n; v++) {
                if (parent[v] == -1 && residualGraph[u][v] > 0) {
                    parent[v] = u;
                    int minCapacity = min(capacity, residualGraph[u][v]);
                    if (v == sink) {
                        maxFlow += minCapacity;
                        int current = v;
                        while (current != source) {
                            int previous = parent[current];
                            residualGraph[previous][current] -= minCapacity;
                            residualGraph[current][previous] += minCapacity;
                            current = previous;
                        }
                        break;
                    }
                    q.push({v, minCapacity});
                }
            }
        }

        if (parent[sink] == -1) {
            break;
        }
    }

    return maxFlow;
}

int main() {
    int n;  // Number of nodes in the graph
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    // Input the graph with capacities
    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v, capacity;
        cout << "Enter edge (u, v) and its capacity: ";
        cin >> u >> v >> capacity;
        graph[u][v] = capacity;
    }

    int source, sink;
    cout << "Enter the source node: ";
    cin >> source;
    cout << "Enter the sink node: ";
    cin >> sink;

    int maxFlow = fordFulkerson(graph, source, sink);
    cout << "Maximum Flow: " << maxFlow << endl;

    return 0;
}

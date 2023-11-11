#include <bits/stdc++.h>
using namespace std;

bool isCycle(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &stack) {
  stack[u] = 1;

  if (!visited[u]) {
    visited[u] = 1;

    for (int i : adj[u]) {
      if (!visited[i]) {
        if (isCycle(i, adj, visited, stack)) {
          return true;
        }
      } else if (stack[i]) {
        return true;
      }
    }
  }
  stack[u]=false;

  return false;
}

int main() {

  int V, E;

  cin >> V >> E;

  vector<vector<int>> adj(V);

  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  bool CycleExists = false;
  vector<int> stack(V, 0);
  vector<bool> visited(V, 0);

  for (int i = 0; i < V; i++) {
    if (!visited[i] && isCycle(i, adj, visited, stack)) {
      CycleExists = true;
    }
  }

  if (CycleExists) {
    cout << "Cycle is present\n";
  } else {
    cout << "Cycle is not present\n";
  }
}
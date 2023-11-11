#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;

bool iscycle(vector<int> adj[N], bool visited[N], int start, int parent) {

  visited[start] = true;

  for (auto it : adj[start]) {

    if (it != parent) {
      if (visited[it])
        return true;
      if (!visited[it] && iscycle(adj, visited, it, start)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  int node, edge;
  cin >> node >> edge;

  bool visited[N] = {0};
  vector<int> adj[N];
  int x, y;
  for (int i = 0; i < edge; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  bool cycle = false;
  for (int i = 0; i < node; i++) {
    if (!visited[i] && iscycle(adj, visited, i, -1)) {
      cycle = true;
      break;
    }
  }

  if (cycle)
    cout << "Cycle exist" << endl ;
  else 
    cout << "Cycle is not exist" << endl;

  return 0;
}
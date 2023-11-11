#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
vector<int> adj[N];
bool vis[N] = {0};


iscycle(int start, int parent) {
  vis[start] = 1;
  for (auto it : adj[start]) {
    if (it != parent) {
      if (vis[it])
        return true;

      if (!vis[it] && iscycle(it, start)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  int node, edge;
  cin >> node >> edge;

  int x, y;
  for (int i = 0; i < edge; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  bool cycle = false;

  for (int i = 0; i < node; i++) {
    if (!vis[i] && iscycle(i, -1)) {
      cycle = 1;
      break;
    }
  }

  if (cycle)
    cout << "true" << endl;
  else
    cout << "false" << endl;

  return 0;
}
#include <iostream>
#include <list>
#include <stack>
#include <vector>

#define NIL -1
using namespace std;

int count = 0;
//std::vector<std::pair<int, int>> bridges;

void BCCUtil(int u, const vector<list<int>> &adj, int disc[], int low[],
             list<pair<int, int>> *st, int parent[]) {
  static int time = 0;
  int children = 0;

  disc[u] = low[u] = ++time;

  for (int v : adj[u]) {
    if (disc[v] == -1) {
      children++;
      parent[v] = u;
      st->push_back({u, v});
      BCCUtil(v, adj, disc, low, st, parent);

      low[u] = min(low[u], low[v]);

      if ((disc[u] == 1 && children > 1) ||
          (disc[u] > 1 && low[v] >= disc[u])) {
        while (st->back() != make_pair(u, v)) {
          if (st->back().first < st->back().second)
            cout << st->back().first << "--" << st->back().second << endl;
          else
            cout << st->back().second << "--" << st->back().first << endl;
          st->pop_back();
        }
        if (st->back().first < st->back().second)
          cout << st->back().first << "--" << st->back().second << endl;
        else
          cout << st->back().second << "--" << st->back().first << endl;
        st->pop_back();
        count++;
        cout<<"-"<<endl;
      }
    } else if (v != parent[u]) {
      low[u] = min(low[u], disc[v]);
      if (disc[v] < disc[u]) {
        st->push_back({u, v});
      }
    }
  }

 // cout<<endl;
}

void findBiconnectedComponents(const vector<list<int>> &adj, int V) {
  int *disc = new int[V];
  int *low = new int[V];
  int *parent = new int[V];
  list<pair<int, int>> *st = new list<pair<int, int>>[V];

  for (int i = V-1; i >= 0; i--) {
    disc[i] = NIL;
    low[i] = NIL;
    parent[i] = NIL;
  }

  for (int i = V-1; i >= 0; i--) {
    if (disc[i] == NIL)
      {BCCUtil(i, adj, disc, low, st, parent);}

    int j = 0;
    while (!st->empty()) {
      j = 1;
      if (st->back().first < st->back().second)
        cout << st->back().first << "--" << st->back().second << endl;
      else
        cout << st->back().second << "--" << st->back().first << endl;
      st->pop_back();

      cout<<endl;
    }
    if (j == 1) {
      cout << endl;
       //cout<<"-"<<endl;
      count++;
    }
   
  }
}

int main() {
  int V, E;
  cin >> V;
  cin >> E;

  vector<list<int>> adj(V);

  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  

  findBiconnectedComponents(adj, V);

 // cout << "Above are " << count << " biconnected components in the graph";
  return 0;
}

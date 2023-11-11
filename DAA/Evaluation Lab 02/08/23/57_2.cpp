#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

bool visited[N];

vector<int> adj[N];
vector<int> indegree(N, 0);
vector<int> indegree1(N, 0);

int main() {
  int node, edge;
  cin >> node >> edge;

  int count2 = 0;

  int x, y;
  for (int i = 0; i < edge; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    indegree[y]++;
     indegree1[y]++;
  }

  for (int i = 0; i < node; i++) {
    int a = adj[i].size();
    if (count2 < a)
      count2 = a;
  }
  // cout<<count<<endl;
  int count = 0;

  queue<int> p;

  stack<int> q;

  for (int i = 0; i < node; i++) {
    if (indegree[i] == 0) {
      q.push(i);
      
    }
    if (indegree1[i] == 0) {
      p.push(i);
      
    }
  }
  int count1 = 1;
  // q.top()=p.front();
  // cout<<q.top();

  int d = 0, e = 0;

  while (!q.empty()) {
    
    int c = q.top();
    // cout<<c<<endl;

    e += q.top();
    // cout<<a<<b<<endl;

    q.pop();

    for (auto it : adj[c]) {
      indegree[it]--;
      if (indegree[it] == 0) {
        q.push(it);
      }
    }
  }

  while (!p.empty()) {
    
    int d = p.front();
    //cout << d<< endl;

    d += p.front();
    // cout<<a<<b<<endl;

    p.pop();

    for (auto it : adj[d]) {
      indegree1[it]--;
      if (indegree1[it] == 0) {
        p.push(it);
      }
    }
  }
  if (d != e)
    cout << count2 - 1 << endl;
  else
    cout << count2 << endl;


}
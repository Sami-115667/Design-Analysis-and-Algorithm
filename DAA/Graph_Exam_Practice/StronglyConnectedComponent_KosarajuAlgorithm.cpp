#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
vector<int> rev[N];

void dfs1(vector<int> adj[N], bool visited[N], int start, int node, stack<int> &mystack) {
    visited[start] = true;
    for (auto it : adj[start]) {
        if (!visited[it]) {
            dfs1(adj, visited, it, node, mystack);
        }
    }
    mystack.push(start);
}

void reverseGraph(vector<int> rev[N], vector<int> adj[N], int node) {
    for (int i = 0; i < node; i++) {
        for (auto it : adj[i]) {
            rev[it].push_back(i);
        }
    }
}

void dfs2(vector<int> rev[N], bool visited[N], int start, int node) {
    cout << start << " ";
    visited[start] = true;
    for (auto it : rev[start]) {
        if (!visited[it]) {
            dfs2(rev, visited, it, node);
        }
    }
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
    }

    stack<int> mystack;

    for (int i = 0; i < node; i++) {
        if (!visited[i])
            dfs1(adj, visited, i, node, mystack);
    }

    for (int i = 0; i < node; i++) {
        visited[i] = false;
    }

    reverseGraph(rev, adj, node);

    while (!mystack.empty()) {
        int x = mystack.top();
        mystack.pop();

        if (!visited[x]) {
            dfs2(rev, visited, x, node);
            cout << endl;
        }
    }

    return 0;
}


 
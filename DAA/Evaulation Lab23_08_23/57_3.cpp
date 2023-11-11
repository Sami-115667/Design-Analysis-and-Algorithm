#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& graph) {
    int n = graph.size();
    
    
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][k] < INF && graph[k][j] < INF) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}

int main() {

    freopen("input3.txt","r",stdin);
    freopen("output3.txt","w",stdout);
    int n, m;
    cin >> n >> m;




    
    vector<vector<int>> graph(n, vector<int>(n, INF));

   
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w; 
    }

    
    for (int i = 0; i < n; ++i) {
        graph[i][i] = 0;
    }

    
    floydWarshall(graph);

 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i==j)
            continue;
            else if (graph[i][j] == INF) {
                cout <<i<<" to "<<j<< ":infinity "<<endl;
            } else {
                cout <<i<<" to "<<j<<":"<< graph[i][j] << " "<<endl;
            }
        }
       
    }

    return 0;
}

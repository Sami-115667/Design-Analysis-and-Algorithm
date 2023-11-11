#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;

bool visited[N];

vector<int> adj[N];

void DFS(int node){
    visited[node]=1;
    cout<<node<<" ";

    vector<int>:: iterator it;
    for(it =adj[node].begin();it !=adj[node].end();it++){
        if(visited[*it]);
        else{
            DFS(*it);
        }
    }
}

int main(){
   int node, edge;
   cin>>node>>edge;

    for(int i=0;i<=node;i++){
        visited[i]=false;
    }

   int x,y;
   for(int i=0;i<edge;i++){
    cin>>x>>y;
    adj[x].push_back(y);
    //adj[y].push_back(x);
   }

   DFS(0);
}
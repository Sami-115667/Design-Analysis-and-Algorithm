#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;

bool visited[N];
 int s[N],e[N], cnt=0;

vector<int> adj[N];

void DFS(int node){
    
    visited[node]=1;

    if(visited[node])
        s[node]=++cnt;
    
   // cout<<node<<" ";

    vector<int>:: iterator it;
    for(it =adj[node].begin();it !=adj[node].end();it++){
        if(visited[*it]);
            
        
        else{
            DFS(*it);

             if(visited[node])
             e[node]=++cnt;
        }
    }


   
}

int main(){
   int node, edge;
   cin>>node>>edge;

   

    for(int i=0;i<node;i++){
        visited[i]=false;
    }

   int x,y;
   for(int i=0;i<edge;i++){
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
   }
    for(int i=0;i<node;i++)
    DFS(0);

   for(int i=0;i<node;i++){
    cout<<i<<": "<<s[i]<<" "<<e[i]<<endl;
   }
}
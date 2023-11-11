#include <bits/stdc++.h>
using namespace std;
const int N =1e5+2;
bool visited[N] ={0};
vector<int>adj[N];



void DFS(vector<int>  adj[N],bool visited[N],int start,int node){
    cout<<start<<" ";
    visited[start]=true;
    for(int i=0;i<node;i++){
        for(auto it: adj[start]){   // if i want to initialize adj[start] then there will one graph but there i can print multiple graph. for this the 
                            // time complexity is V(V+E)
            if(!visited[it])
            DFS(adj, visited, it, node);
        }
    }
}


int main(){
    int node,edge;
    cin>>node>>edge;

    int x,y;
    for(int i=0;i<edge;i++){
        cin>>x>>y;
        adj[x].push_back(y);
       // adj[y].push_back(x);
    }


    DFS(adj,visited,0,node);



    return 0;
}
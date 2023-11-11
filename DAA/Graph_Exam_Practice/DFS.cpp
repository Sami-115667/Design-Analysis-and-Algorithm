#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;


void dfs(vector<int>adj[N],bool visited[N],int start,int node){



    cout<<start<<" ";
    visited[start]=1;
    for(int i=0;i<node;i++){
        for(auto it: adj[start]){
            if(!visited[it]){
                dfs(adj,visited,it,node);
            }
        }
    }

   

}



int main(){
    int node,edge;
    cin>>node>>edge;

    bool visited[N]={0};
    vector<int>adj[N];
    int x,y;
    for(int i=0;i<edge;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    dfs(adj,visited,0,node);
    return 0;


}
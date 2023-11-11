#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;


void bfs(vector<int>adj[N],bool visited[N],int start,int node){

    queue<int>q;
    q.push(start);
    visited[start]=true;

    while (!q.empty()){
        cout<<q.front()<<" ";
        int n=q.front();
        q.pop();

        for(int i=0;i<node;i++){
            for(auto it : adj[n]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push(it);
                }
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

    bfs(adj,visited,0,node);
    return 0;


}
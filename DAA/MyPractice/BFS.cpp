#include <bits/stdc++.h>
using namespace std;
const int N =1e5+2;
bool visited[N] ={0};
vector<int>adj[N];



void BFS(vector<int>  adj[N],bool visited[N],int start,int node){
   queue<int>q;
   q.push(start);

    visited[start]=true;
    while (!q.empty()) {
        int x=q.front();
        q.pop();
        cout<<x<<" ";

        //for(int i=0;i<node;i++){
        for(auto it: adj[x]){
            if(!visited[it]){
                visited[it]=true;
                q.push(it);
            }
            
        }
   // }
    }
    
}


int main(){
    int node,edge;
    cin>>node>>edge;

    int x,y;
    for(int i=0;i<edge;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    BFS(adj,visited,0,node);



    return 0;
}
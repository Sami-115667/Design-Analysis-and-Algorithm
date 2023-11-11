#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<int>adj[N];
bool vis[N]={0};

void bfs(int start,int node ,int &time){
   time++;

    cout<<start<<" starting time is " <<time<<endl;

    
    vis[start]=1;
    for(auto it: adj[start]){
        if(!vis[it])
        bfs(it, node,time);
        ;
    }
    time++;


    cout<<start<<" finishing time is " <<time<<endl;



}
int main (){
    int node, edge;
    cin>> node >>edge;

    int x,y;
    for(int i=0;i<edge;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int time=0;

    for(int i=0;i<node;i++){
        if(!vis[i])
        bfs(i, node,time);
    }
    return 0;
}
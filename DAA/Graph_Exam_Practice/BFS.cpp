#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
bool  vis[N]={0};
vector<int>adj[N];




int main(){
    int node,edge;
    cin>>node>>edge;


    int x,y;
    for(int i=0;i<edge;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue <int> q;
    q.push(0);
    vis[0]=true;

    while (!q.empty()){
        cout<<q.front()<<" ";
        int n=q.front();
        q.pop();

        for(int i=0;i<node;i++){
            for(auto it : adj[n]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push(it);
                }
            }
        }

    }



    return 0 ;



}
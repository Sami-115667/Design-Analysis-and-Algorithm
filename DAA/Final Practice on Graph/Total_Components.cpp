#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<int>adj[N];
bool vis[N]={0};

int get_component(int i){
    if(vis[i])
    return 0;
   vis[i]=1;
   int ans=1;
   for(auto it: adj[i]){
    if(!vis[it]){
        ans+=get_component(it);
        vis[it]=1;
    }
   }
   return ans;
}

int main (){
    int node, edge;
    cin>> node >>edge;
    vector<int>components;

    int x,y;
    for(int i=0;i<edge;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0;i<node;i++){
        if(!vis[i])
        components.push_back(get_component(i));
    }

    for(auto it : components){
        cout<<it<<endl;
    }



    return 0;
}
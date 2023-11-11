#include <bits/stdc++.h>
using namespace std;
const int n=1e5+2;
bool vis[n];
vector<int>adj[n];

int main (){
  

    int v,e;
    cin>>v>>e;
    int a[v]={0};

      for(int i=0;i<v;i++)
        vis[i]=0;

    int source ,dest;
    for(int i=0;i<e;i++)
    {
        cin>>source >>dest;
         adj[source].push_back(dest);
        
    }

    queue<int>q;

    q.push(0);
    vis[0]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        //cout<<node<<endl;

       vector<int> ::iterator  it;
       for(it=adj[node].begin(); it!=adj[node].end();it++){
        if(!vis[*it]){
            vis[*it]=1;
            a[*it]=node+1;
            q.push(*it);
        }

       }


    }

    for(int i=0;i<v;i++){
        if(vis[i]!=0){
            cout<<i<<": "<<a[i]<<endl;
        }
        else {
        cout<<i<<": Not Reachable"<<endl;
        }
        
    }


}
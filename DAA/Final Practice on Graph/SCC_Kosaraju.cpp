#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<int>adj[N];
vector<int>rev[N];
bool vis[N]={0};
stack<int>st;

void bfs1(int start,int node){

    
    vis[start]=1;
    for(auto it: adj[start]){
        if(!vis[it])
        bfs1(it, node);
    }
    st.push(start);

}




void reverse_graph(int node){
  

  for (int i = 0; i < node; i++) {
        for (auto it : adj[i]) {
            rev[it].push_back(i);
        }
    }


}


void bfs2(int start,int node){

    
    vis[start]=1;
    cout<<start<<" ";
    for(auto it: rev[start]){
        if(!vis[it])
        bfs2(it, node);
    }
   // st.push(start);

}





int main (){
    int node, edge;
    cin>> node >>edge;

    int x,y;
    for(int i=0;i<edge;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
       // adj[y].push_back(x);
    }

    for(int i=0;i<node;i++){
        if(!vis[i])
        bfs1(i, node);
    }


    for (int i = 0; i < node; i++) {
        vis[i] = 0;
    }


    reverse_graph(node);



    while (!st.empty()) {
        
        int x=st.top();
        st.pop();
        if(!vis[x]){
          bfs2(x,node);
          cout<<endl;
        }
    
    }



    return 0;
}
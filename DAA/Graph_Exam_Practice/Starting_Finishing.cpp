#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;

 vector<int>starting(N,0);
 vector<int>finish(N,0);


void dfs(vector<int>adj[N],bool visited[N],int start,int node,int & time){

    time++;
 
  starting[start]=time;
  visited[start]=true;
  
        for(auto it: adj[start]){
            if(!visited[it]){
                dfs(adj,visited,it,node,time);
            }
           // else {
                
           // }
        }time++;
                finish[start]=time;
               // cout<<start<<" ";
    
    


   

   

}



int main(){
    int node,edge;
    cin>>node>>edge;
    int time=0;

    bool visited[N]={0};
    vector<int>adj[N];
    int x,y;
    for(int i=0;i<edge;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(adj,visited,0,node,time);

    for(int i=0;i<node;i++){
        cout<<i<<" "<<starting[i]<<" "<<finish[i]<<endl;
    }
    return 0;


}
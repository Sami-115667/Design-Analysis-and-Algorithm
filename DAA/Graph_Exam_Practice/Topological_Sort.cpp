#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;


void topological(vector<int>adj[N],vector<int>indegree,int node){

    queue<int>q;
    for(int i=0;i<node;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    

    while (!q.empty()) {
        
        cout<<q.front()<<" ";
        int x=q.front();
        q.pop();
        for(auto it: adj[x]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
}



int main(){
    int node,edge;
    cin>>node>>edge;

   // bool visited[N]={0};
     
    vector<int> adj[N];
    vector<int>indegree(N,0);
    int x,y;
    for(int i=0;i<edge;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;

    }

    topological(adj,indegree,node);
    return 0;


}
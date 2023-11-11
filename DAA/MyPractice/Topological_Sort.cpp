#include <bits/stdc++.h>
using namespace std;
const int N =1e5+2;
bool visited[N] ={0};
vector<int>adj[N];



void TopologicalSort(vector<int>  adj[N],vector<int>indegree,int node){
   queue<int>q;
   for(int i=0;i<node;i++){
    if(indegree[i]==0){
        q.push(i);
    }
   }
   while (!q.empty()) {
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        for(auto it: adj[x])
        {
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
        }
   }
}


int main(){
    int node,edge;
    cin>>node>>edge;
    vector<int>indegree(node,0);
    int x,y;
    for(int i=0;i<edge;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        //adj[y].push_back(x);
        indegree[y]++;
    }


    TopologicalSort(adj,indegree,node);



    return 0;
}
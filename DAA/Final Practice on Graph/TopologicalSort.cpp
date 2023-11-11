#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<int>adj[N];
bool vis[N]={0};
int indegree[N]={0};

void topology(int node){

    queue<int>q;
    for(int i=0;i<node;i++){
        if(indegree[i]==0)
        q.push(i);
    }

    while (!q.empty()) {
        int x=q.front();
        q.pop();
        cout<<x<<" ";
        for(auto it: adj[x]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
}


int main (){
    int node, edge;
    cin>> node >>edge;

    int x,y;
    for(int i=0;i<edge;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        //adj[y].push_back(x);
        indegree[y]++;
    }

        topology( node);
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;

bool visited[N];

vector<int> adj[N];
vector<int> indegree(N,0 );



int main(){
   int node, edge;
   cin>>node>>edge;

   int count=0;

   int x,y;
   for(int i=0;i<edge;i++){
    cin>>x>>y;
    adj[x].push_back(y);
    indegree[y]++;
   }

   stack<int> q;
   for(int i=0;i<node;i++){
    if(indegree[i]==0)
    q.push(i);
   }

   while (!q.empty()) {
    count++;
    int a= q.top();
    cout<<a<<endl;
    q.pop();
    for(auto it : adj[a]){
        indegree[it]--;
        if(indegree[it]==0){
            q.push(it);
        }
    }
   }

   
}
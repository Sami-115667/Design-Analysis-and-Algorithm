#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;


vector<int> adj[N];



int main(){
   int node, edge;
   cin>>node>>edge;

  
   int x,y;
   for(int i=0;i<edge;i++){
    cin>>x>>y;
    adj[x].push_back(y);
   }

   for(int i=0;i<node;i++){
    cout<<i<<": ";
    for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }

        cout<<endl;
   }

   return 0;
}
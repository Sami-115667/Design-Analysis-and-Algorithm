#include <bits/stdc++.h>
using namespace std;
const int N =1e5+2;
bool visited[N] ={0};
vector<int>adj[N];

int get_component(int i){

    if(visited[i])
        return 0;

    visited[i]=true;
    int ans=1;

    for(auto it: adj[i]){
         if(!visited[it]){
            ans+=(get_component(it));
            visited[it]=true;
        }
    }
    return ans;

}




int main(){
    int node,edge;
    cin>>node>>edge;
    vector<int>Components;

    int x,y;
    for(int i=0;i<edge;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        //adj[y].push_back(x);
    }

    for(int i =0;i<node;i++ ){
        if(!visited[i]){
            Components.push_back(get_component(i));
        }
    }

    for(auto it: Components){
        cout<<it<<" ";
    }

    cout<<endl<<Components.size()<<endl;


   



    return 0;
}
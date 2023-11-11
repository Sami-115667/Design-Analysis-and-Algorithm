#include <bits/stdc++.h>
using namespace std;





int main(){
  int n,m;
  cin>>n>>m;

  char arr[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
    {
        cin>>arr[i][j];
    }
  }
   int arrr[n]={0};

  for(int i=0;i<n;i++){
    
    for(int j=0;j<m;j++)
    {
        
       if(arr[i][j]=='.'){
       arrr[i]=1;
        break;
       }
    }
   
  }
  int count=0;
  for(int i=0;i<n-1;i++){
    if(arrr[i]!=arrr[i+1])
    count++;
  }
  cout<<count<<endl;
 
   return 0;
}
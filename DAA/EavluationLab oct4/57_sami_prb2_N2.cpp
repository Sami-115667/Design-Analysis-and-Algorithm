#include <bits/stdc++.h>
using namespace std;
int N =9;
vector<int>dp(N,1);

int lis(vector<int>&v,int n,int k){    



    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[i]>v[j] && v[i]-v[j]>=k){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }

    for(int i=0;i<dp.size();i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;


    cout<<dp[n-1]<<endl;


    for(int i=1;i<=dp[n-1];i++){
        for(int j=0;j<=dp.size();j++){
            if(i==dp[j]){
                cout<<v[j]<<" ";
                break;
            }
        }
    }
    cout<<endl;


    return dp[n-1];
}
int main (){

     freopen("input2.txt","r",stdin);
     freopen("output2.txt","w",stdout);
    vector<int>a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
        //cout<<b[i]<<endl;
    }
    int k;
    cin>>k;

    lis(a,n,k);



}
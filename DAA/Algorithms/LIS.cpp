#include <bits/stdc++.h>
using namespace std;
int N =1e5+2;
vector<int>dp(N,1);

int lis(vector<int>&v,int n){



    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[i]>v[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }


    return dp[n-1];
}
int main (){
    vector<int>a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
        //cout<<b[i]<<endl;
    }

    cout<<lis(a,n);



}
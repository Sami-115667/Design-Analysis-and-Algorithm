#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplicationMemo(vector<int>& matrixsize, int i, int j, vector<vector<int>>& memo) {
    if (i == j) {
        return 0;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int minCost = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = matrixChainMultiplicationMemo(matrixsize, i, k, memo) +
                    matrixChainMultiplicationMemo(matrixsize, k + 1, j, memo) +
                    matrixsize[i - 1] * matrixsize[k] * matrixsize[j];
        minCost = min(minCost, cost);
    }

    memo[i][j] = minCost;
    return minCost;
}

int matrixChainMultiplicationMemoization(vector<int>& matrixsize) {
    int n = matrixsize.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return matrixChainMultiplicationMemo(matrixsize, 1, n - 1, memo);
}



int main() {

    freopen("input1_1.txt","r",stdin);
     freopen("output1_1.txt","w",stdout);
    int t;
     cin>>t;
     while(t--){


    int n;
    cin>>n;

   int k=n-1;

   

    vector<int> matrixsize ;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        matrixsize.push_back(x);
    }

    int minMultiplications = matrixChainMultiplicationMemoization(matrixsize);
    
    cout << "Optimal Cost: " << minMultiplications << endl;
    cout<<endl;
     }
    
    return 0;
}

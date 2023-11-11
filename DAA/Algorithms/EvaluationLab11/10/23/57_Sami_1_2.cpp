#include <bits/stdc++.h>

using namespace std;

int matrixChainMultiplicationTable(vector<int>& matrixes) {
    int n = matrixes.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + matrixes[i - 1] * matrixes[k] * matrixes[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    cout << "Table Print by Itreating :" << endl;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i <= j)
                cout << dp[i][j] << "\t";
            else
                cout << "\t\t";
        }
        cout << endl;
    }

    return dp[1][n - 1];
}

int main() {

     freopen("input1_2.txt","r",stdin);
     freopen("output1_2.txt","w",stdout);

     int t;
     cin>>t;
     while(t--){
            int n;
    
    cin >> n;

    vector<int> matrixes(n);

    for (int i = 0; i < n; i++) {
        cin >> matrixes[i];
    }

    int cost = matrixChainMultiplicationTable(matrixes);
    cout << "\nOptimal Cost is : " << cost << endl;


    cout<<endl;

     }





    

    return 0;
}
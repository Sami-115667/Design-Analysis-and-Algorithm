#include <bits/stdc++.h>
using namespace std;


string findLCS(string seq1, string seq2) {
    int m = seq1.length();
    int n = seq2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

 
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = m, j = n;
    string lcsStr = "";

  
    while (i > 0 && j > 0) {
        if (seq1[i - 1] == seq2[j - 1]) {
            lcsStr = seq1[i - 1] + lcsStr;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    
    for (int row = 0; row <= m; row++) {
        for (int col = 0; col <= n; col++) {
            cout << dp[row][col] << " ";
        }
        cout << endl;
    }

    return lcsStr;
}

int main() {
     freopen("input3.txt","r",stdin);
     freopen("output3.txt","w",stdout);
    string seq1;
    string seq2;

    cin >> seq1;
    cin >> seq2;

    
    string longestCommonSubsequence = findLCS(seq1, seq2);

    cout<<endl;
    
    cout<< longestCommonSubsequence.length()<<endl;

    
    cout << longestCommonSubsequence << endl;

    return 0;
}

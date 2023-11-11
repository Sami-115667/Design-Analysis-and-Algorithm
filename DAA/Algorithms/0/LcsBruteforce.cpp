#include <iostream>
#include <string>
#include <vector>

using namespace std;

string lcsBruteForce(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    string lcs;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Generate all possible subsequences and find the longest common one.
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS from the dp table.
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    string result = lcsBruteForce(X, Y);

    cout << "Longest Common Subsequence: " << result << endl;

    return 0;
}

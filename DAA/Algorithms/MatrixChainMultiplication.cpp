#include <iostream>
#include <vector>
#include <climits> // Include this header for INT_MAX

using namespace std;

// Function to find the minimum number of scalar multiplications for MCM
int matrixChainMultiplication(vector<int>& dimensions) {
    int n = dimensions.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Chain length is one, so no multiplications are needed
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    for (int chainLen = 2; chainLen < n; chainLen++) {
        for (int i = 1; i < n - chainLen + 1; i++) {
            int j = i + chainLen - 1;
            dp[i][j] = INT_MAX; // INT_MAX is defined in <climits>

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    vector<int> dimensions(n);
    cout << "Enter the dimensions of each matrix:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> dimensions[i];
    }

    int minMultiplications = matrixChainMultiplication(dimensions);

    cout << "Minimum number of scalar multiplications: " << minMultiplications << endl;

    return 0;
}

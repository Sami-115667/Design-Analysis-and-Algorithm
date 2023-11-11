#include <iostream>
#include <vector>



using namespace std;

int maximizeValue(int n, int W, vector<int>& weights, vector<int>& values) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            
            dp[i][w] = dp[i - 1][w];

            // Check if including the current item is better
            if (weights[i - 1] <= w) {
                int newValue = dp[i - 1][w - weights[i - 1]] + (values[i - 1] + w - weights[i - 2]);
                dp[i][w] = max(dp[i][w], newValue);
            }
        }
    }

     for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }

    int maxValue = dp[n][W];
    return maxValue;
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> weights(n);
    vector<int> values(n);

    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
    }

    int maxVal = maximizeValue(n, W, weights, values);
    cout << maxVal << endl;

    
   

    return 0;
}

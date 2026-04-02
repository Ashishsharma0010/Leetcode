#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        // dp[i][j][k] → max coins at (i,j) using k neutralizations
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

        // Base case
        if (coins[0][0] >= 0) {
            dp[0][0][0] = coins[0][0];
        } else {
            dp[0][0][0] = coins[0][0]; // take loss
            dp[0][0][1] = 0;           // neutralize
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                for (int k = 0; k <= 2; k++) {

                    int best = INT_MIN;

                    // from top
                    if (i > 0 && dp[i-1][j][k] != INT_MIN) {
                        best = max(best, dp[i-1][j][k] + coins[i][j]);
                    }

                    // from left
                    if (j > 0 && dp[i][j-1][k] != INT_MIN) {
                        best = max(best, dp[i][j-1][k] + coins[i][j]);
                    }

                    dp[i][j][k] = max(dp[i][j][k], best);

                    // Neutralization case
                    if (coins[i][j] < 0 && k > 0) {
                        int bestNeutral = INT_MIN;

                        if (i > 0 && dp[i-1][j][k-1] != INT_MIN) {
                            bestNeutral = max(bestNeutral, dp[i-1][j][k-1]);
                        }

                        if (j > 0 && dp[i][j-1][k-1] != INT_MIN) {
                            bestNeutral = max(bestNeutral, dp[i][j-1][k-1]);
                        }

                        dp[i][j][k] = max(dp[i][j][k], bestNeutral);
                    }
                }
            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};
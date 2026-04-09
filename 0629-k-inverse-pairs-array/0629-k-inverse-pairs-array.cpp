class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<long long> prefix(k + 2, 0);
            for (int j = 0; j <= k; j++)
                prefix[j + 1] = (prefix[j] + dp[i - 1][j]) % MOD;

            for (int j = 0; j <= k; j++) {
                int lo = j - min(j, i - 1);
                int hi = j;
                dp[i][j] = (prefix[hi + 1] - prefix[lo] + MOD) % MOD;
            }
        }

        return dp[n][k];
    }
};
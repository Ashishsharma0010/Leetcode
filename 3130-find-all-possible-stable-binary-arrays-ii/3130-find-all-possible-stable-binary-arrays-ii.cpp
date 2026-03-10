class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        
        vector<vector<array<long long, 2>>> dp(
            zero + 1, vector<array<long long, 2>>(one + 1, {0, 0})
        );
        
        // Base cases: pure 0s or pure 1s — valid only if length <= limit
        for (int i = 1; i <= zero; i++)
            dp[i][0][0] = (i <= limit) ? 1 : 0;
        for (int j = 1; j <= one; j++)
            dp[0][j][1] = (j <= limit) ? 1 : 0;
        
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                // Append 0: sum all arrays (i-1 zeros, j ones)
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
                // Subtract cases that create a run of 0s longer than limit
                if (i > limit)
                    dp[i][j][0] = (dp[i][j][0] - dp[i-limit-1][j][1] + MOD) % MOD;
                
                // Append 1: sum all arrays (i zeros, j-1 ones)
                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1]) % MOD;
                // Subtract cases that create a run of 1s longer than limit
                if (j > limit)
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j-limit-1][0] + MOD) % MOD;
            }
        }
        
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int n = s.size();
        unordered_set<long long> powersOf5;
        long long val = 1;
        for (int i = 0; i < 20; i++) {
            powersOf5.insert(val);
            val *= 5;
        }
        
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            long long num = 0;
            for (int j = i - 1; j >= 0; j--) {
                num += (long long)(s[j] - '0') << (i - 1 - j);
                if (s[j] == '0') continue;
                if (powersOf5.count(num) && dp[j] != INT_MAX) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};
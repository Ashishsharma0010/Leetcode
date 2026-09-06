class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int x : nums) total += x;
        
        if (abs(target) > total || (total + target) % 2 != 0) return 0;
        
        int P = (total + target) / 2;
        
        vector<int> dp(P + 1, 0);
        dp[0] = 1;
        
        for (int x : nums) {
            for (int j = P; j >= x; j--) {
                dp[j] += dp[j - x];
            }
        }
        
        return dp[P];
    }
};
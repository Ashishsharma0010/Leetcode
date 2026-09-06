class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<long long>> C;
    
    void buildPascal(int n) {
        C.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }
    }
    
    pair<int, long long> solve(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return {n, 1};
        
        vector<int> left, right;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        
        auto [leftSize, leftWays] = solve(left);
        auto [rightSize, rightWays] = solve(right);
        
        long long ways = (C[leftSize + rightSize][leftSize] * leftWays) % MOD;
        ways = (ways * rightWays) % MOD;
        
        return {n, ways};
    }
    
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        buildPascal(n);
        auto [size, totalWays] = solve(nums);
        return (int)((totalWays - 1 + MOD) % MOD);
    }
};
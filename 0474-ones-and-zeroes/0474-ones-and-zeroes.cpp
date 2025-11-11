class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
          vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
                  
                          // Process each string
                                  for (string &s : strs) {
                                              int zeros = count(s.begin(), s.end(), '0');
                                                          int ones = s.size() - zeros;
                                                                      
                                                                                  // Traverse backward to ensure 0/1 knapsack (each string used once)
                                                                                              for (int i = m; i >= zeros; --i) {
                                                                                                              for (int j = n; j >= ones; --j) {
                                                                                                                                  dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                                                                                                                                                  }
                                                                                                                                                              }
                                                                                                                                                                      }
                                                                                                                                                                              
                                                                                                                                                                                      return dp[m][n];
        
    }
};

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1e9 + 7;

        vector<vector<int>> dpR(m, vector<int>(n, 0));
        vector<vector<int>> dpD(m, vector<int>(n, 0));

        // Number of ways to start at (0,0)
        dpR[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int right = dpR[i][j];
                int down = dpD[i][j];

                if (grid[i][j] == 1) {

                    // Entered mirror while moving right:
                    // Reflect downward.
                    if (right && i + 1 < m) {
                        dpD[i + 1][j] =
                            (dpD[i + 1][j] + right) % MOD;
                    }

                    // Entered mirror while moving down:
                    // Reflect rightward.
                    if (down && j + 1 < n) {
                        dpR[i][j + 1] =
                            (dpR[i][j + 1] + down) % MOD;
                    }

                } else {

                    int ways = (right + down) % MOD;

                    // Reached destination
                    if (i == m - 1 && j == n - 1) {
                        return ways;
                    }

                    // Move right
                    if (j + 1 < n) {
                        dpR[i][j + 1] =
                            (dpR[i][j + 1] + ways) % MOD;
                    }

                    // Move down
                    if (i + 1 < m) {
                        dpD[i + 1][j] =
                            (dpD[i + 1][j] + ways) % MOD;
                    }
                }
            }
        }

        return 0;
    }
};

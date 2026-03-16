class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
           int m = grid.size(), n = grid[0].size();

    vector<vector<int>> diag1(m, vector<int>(n, 0));
    vector<vector<int>> diag2(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            diag1[i][j] = grid[i][j] + (i > 0 && j > 0 ? diag1[i-1][j-1] : 0);
            diag2[i][j] = grid[i][j] + (i > 0 && j < n-1 ? diag2[i-1][j+1] : 0);
        }
    }

    auto getD1 = [&](int r1, int c1, int r2, int c2) -> int {
        return diag1[r2][c2] - (r1 > 0 && c1 > 0 ? diag1[r1-1][c1-1] : 0);
    };
    auto getD2 = [&](int r1, int c1, int r2, int c2) -> int {
        return diag2[r2][c2] - (r1 > 0 && c1 < n-1 ? diag2[r1-1][c1+1] : 0);
    };

    set<int, greater<int>> topVals;

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            topVals.insert(grid[r][c]);

            int maxSize = min({r, m-1-r, c, n-1-c});

            for (int k = 1; k <= maxSize; k++) {
                int topRight = getD1(r-k, c, r, c+k);
                int rightBottom = getD2(r, c+k, r+k, c);
                int bottomLeft = getD1(r, c-k, r+k, c);
                int leftTop = getD2(r-k, c, r, c-k);

                int rhombusSum = topRight + rightBottom + bottomLeft + leftTop
                    - grid[r-k][c] - grid[r][c+k] - grid[r+k][c] - grid[r][c-k];

                topVals.insert(rhombusSum);
            }
        }
    }

    vector<int> result;
    for (int v : topVals) {
        result.push_back(v);
        if (result.size() == 3) break;
    }
    return result;
        
    }
};
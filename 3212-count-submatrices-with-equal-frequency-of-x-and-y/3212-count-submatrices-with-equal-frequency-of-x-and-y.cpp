class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> px(m, vector<int>(n, 0));
        vector<vector<int>> py(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int top     = (i > 0) ? px[i-1][j] : 0;
                int left    = (j > 0) ? px[i][j-1] : 0;
                int topLeft = (i > 0 && j > 0) ? px[i-1][j-1] : 0;
                px[i][j] = top + left - topLeft + (grid[i][j] == 'X' ? 1 : 0);
                
                top     = (i > 0) ? py[i-1][j] : 0;
                left    = (j > 0) ? py[i][j-1] : 0;
                topLeft = (i > 0 && j > 0) ? py[i-1][j-1] : 0;
                py[i][j] = top + left - topLeft + (grid[i][j] == 'Y' ? 1 : 0);
            }
        }
        
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (px[i][j] == py[i][j] && px[i][j] > 0)
                    count++;
        
        return count;
    }
};
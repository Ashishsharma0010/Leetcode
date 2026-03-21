class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int top = x, bot = x + k - 1;
        while (top < bot) {
            for (int col = y; col < y + k; col++)
                swap(grid[top][col], grid[bot][col]);
            top++; bot--;
        }
        return grid;
    }
};
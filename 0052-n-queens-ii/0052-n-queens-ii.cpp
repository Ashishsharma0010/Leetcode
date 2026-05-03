class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        solve(0, n, 0, 0, 0, count);
        return count;
    }

private:
    void solve(int row, int n, int cols, int diag1, int diag2, int& count) {
        if (row == n) { count++; return; }

        int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);
        while (available) {
            int bit = available & (-available);
            available &= available - 1;
            solve(row + 1, n, cols | bit, (diag1 | bit) << 1, (diag2 | bit) >> 1, count);
        }
    }
};
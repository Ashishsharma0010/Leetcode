#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        long long total = 0;
        unordered_map<int,int> freq;

        for (auto &row : grid) {
            for (int x : row) {
                total += x;
                freq[x]++;
            }
        }

        // -------- Horizontal Cuts --------
        unordered_map<int,int> top;
        long long prefix = 0;

        for (int i = 0; i < m - 1; i++) {

            for (int x : grid[i]) {
                top[x]++;
                freq[x]--;
                prefix += x;
            }

            long long suffix = total - prefix;

            if (prefix == suffix) return true;

            long long diff = abs(prefix - suffix);

            // 🔥 IMPORTANT: must be one cell
            if (diff > 100000) continue;

            int val = (int)diff;

            if (prefix > suffix) {
                int rows = i + 1;

                // 1D case
                if (rows == 1) {
                    if (grid[0][0] == val || grid[0][n-1] == val)
                        return true;
                }
                else if (n == 1) {
                    if (grid[0][0] == val || grid[i][0] == val)
                        return true;
                }
                else {
                    if (top[val] > 0) return true;
                }

            } else {
                int rows = m - i - 1;

                if (rows == 1) {
                    if (grid[i+1][0] == val || grid[i+1][n-1] == val)
                        return true;
                }
                else if (n == 1) {
                    if (grid[i+1][0] == val || grid[m-1][0] == val)
                        return true;
                }
                else {
                    if (freq[val] > 0) return true;
                }
            }
        }

        // -------- Vertical Cuts --------
        freq.clear();
        for (auto &row : grid)
            for (int x : row)
                freq[x]++;

        unordered_map<int,int> left;
        prefix = 0;

        for (int j = 0; j < n - 1; j++) {

            for (int i = 0; i < m; i++) {
                int x = grid[i][j];
                left[x]++;
                freq[x]--;
                prefix += x;
            }

            long long suffix = total - prefix;

            if (prefix == suffix) return true;

            long long diff = abs(prefix - suffix);

            // 🔥 IMPORTANT
            if (diff > 100000) continue;

            int val = (int)diff;

            if (prefix > suffix) {
                int cols = j + 1;

                if (cols == 1) {
                    if (grid[0][0] == val || grid[m-1][0] == val)
                        return true;
                }
                else if (m == 1) {
                    if (grid[0][0] == val || grid[0][j] == val)
                        return true;
                }
                else {
                    if (left[val] > 0) return true;
                }

            } else {
                int cols = n - j - 1;

                if (cols == 1) {
                    if (grid[0][j+1] == val || grid[m-1][j+1] == val)
                        return true;
                }
                else if (m == 1) {
                    if (grid[0][j+1] == val || grid[0][n-1] == val)
                        return true;
                }
                else {
                    if (freq[val] > 0) return true;
                }
            }
        }

        return false;
    }
};
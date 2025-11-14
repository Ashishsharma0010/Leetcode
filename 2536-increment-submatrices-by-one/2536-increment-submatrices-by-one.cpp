class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
vector<vector<int>> diff(n+1, vector<int>(n+1, 0));

        // Step 1: Apply difference array updates
                for (auto &q : queries) {
                            int r1 = q[0], c1 = q[1];
                               int r2 = q[2], c2 = q[3];
              diff[r1][c1] += 1;
                 diff[r1][c2 + 1] -= 1;
                         diff[r2 + 1][c1] -= 1;
                             diff[r2 + 1][c2 + 1] += 1;
                                                                                                }
 vector<vector<int>> mat(n, vector<int>(n, 0));
  for (int r = 0; r < n; r++) {
          for (int c = 0; c < n; c++) {
  int up = (r > 0 ? diff[r - 1][c] : 0);
        int left = (c > 0 ? diff[r][c - 1] : 0);
                     int diag = (r > 0 && c > 0 ? diff[r - 1][c - 1] : 0);
    diff[r][c] = diff[r][c] + up + left - diag;
           mat[r][c] = diff[r][c];
                 }
                   }
           return mat;
        
    }
};
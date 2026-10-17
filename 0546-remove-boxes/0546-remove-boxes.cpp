
class Solution {
public:
    int dp[100][100][101];

    int solve(vector<int>& boxes, int l, int r, int k) {
        if (l > r)
            return 0;

        // Compress consecutive equal boxes on the right.
        while (l < r && boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }

        // Check memoization AFTER compression.
        if (dp[l][r][k] != -1)
            return dp[l][r][k];

        // Option 1: Remove the rightmost group now.
        int ans = solve(boxes, l, r - 1, 0)
                + (k + 1) * (k + 1);

        // Option 2: Merge with an earlier box of the same color.
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                int points = solve(boxes, l, i, k + 1)
                           + solve(boxes, i + 1, r - 1, 0);

                ans = max(ans, points);
            }
        }

        return dp[l][r][k] = ans;
    }

    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof(dp));
        return solve(boxes, 0, (int)boxes.size() - 1, 0);
    }
};

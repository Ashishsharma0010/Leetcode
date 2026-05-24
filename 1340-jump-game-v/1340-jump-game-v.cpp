class Solution {
public:
    int n;
    vector<int> dp;

    int solve(int idx, vector<int>& arr, int d) {
        if (dp[idx] != -1)
            return dp[idx];

        int ans = 1;

        // Move Left
        for (int j = idx - 1; j >= max(0, idx - d); j--) {
            // Stop if barrier found
            if (arr[j] >= arr[idx])
                break;

            ans = max(ans, 1 + solve(j, arr, d));
        }

        // Move Right
        for (int j = idx + 1; j <= min(n - 1, idx + d); j++) {
            // Stop if barrier found
            if (arr[j] >= arr[idx])
                break;

            ans = max(ans, 1 + solve(j, arr, d));
        }

        return dp[idx] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        dp.assign(n, -1);

        int result = 1;

        for (int i = 0; i < n; i++) {
            result = max(result, solve(i, arr, d));
        }

        return result;
    }
};
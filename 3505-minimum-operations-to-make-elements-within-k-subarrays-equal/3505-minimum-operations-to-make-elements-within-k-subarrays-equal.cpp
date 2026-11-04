class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> left, right;
        long long sumLeft = 0, sumRight = 0;

        vector<long long> cost(n - x + 1);

        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                int val = *left.rbegin();
                left.erase(left.find(val));
                sumLeft -= val;

                right.insert(val);
                sumRight += val;
            }

            while (left.size() < right.size()) {
                int val = *right.begin();
                right.erase(right.find(val));
                sumRight -= val;

                left.insert(val);
                sumLeft += val;
            }
        };

        for (int i = 0; i < n; i++) {
            if (left.empty() || nums[i] <= *left.rbegin()) {
                left.insert(nums[i]);
                sumLeft += nums[i];
            } else {
                right.insert(nums[i]);
                sumRight += nums[i];
            }

            balance();

            if (i >= x) {
                int val = nums[i - x];

                if (left.find(val) != left.end()) {
                    left.erase(left.find(val));
                    sumLeft -= val;
                } else {
                    right.erase(right.find(val));
                    sumRight -= val;
                }

                balance();
            }

            if (i >= x - 1) {
                long long median = *left.rbegin();

                cost[i - x + 1] =
                    median * left.size() - sumLeft
                    + sumRight - median * right.size();
            }
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {

                dp[j][i] = dp[j][i - 1];

                if (i >= x && dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][i - x] + cost[i - x]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
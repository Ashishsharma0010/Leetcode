class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        sort(arr.begin(), arr.end());

        int n = arr.size();

        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        vector<long long> dp(n, 1);

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                if (arr[i] % arr[j] == 0) {

                    int right = arr[i] / arr[j];

                    if (index.find(right) != index.end()) {

                        int k = index[right];

                        dp[i] = (dp[i] + dp[j] * dp[k]) % MOD;
                    }
                }
            }

            ans = (ans + dp[i]) % MOD;
        }

        return ans;
    }
};
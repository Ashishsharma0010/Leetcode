
class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1) {
                res = (res * a) % MOD;
            }

            a = (a * a) % MOD;
            b /= 2;
        }

        return res;
    }

    int numberOfSequence(int n, vector<int>& sick) {

        vector<long long> fact(n + 1);

        fact[0] = 1;

        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        int k = n - sick.size();

        long long ans = fact[k];

        int prev = -1;

        for (int i = 0; i <= sick.size(); i++) {

            int curr;

            if (i == sick.size()) {
                curr = n;
            } else {
                curr = sick[i];
            }

            int gap = curr - prev - 1;

            // Divide by gap!
            ans = (ans * power(fact[gap], MOD - 2)) % MOD;

            // Middle gap contributes 2^(gap - 1)
            if (i > 0 && i < sick.size() && gap > 1) {
                ans = (ans * power(2, gap - 1)) % MOD;
            }

            prev = curr;
        }

        return ans;
    }
};

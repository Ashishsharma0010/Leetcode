
class Solution {
public:
    long long count(long long prefix, long long next, long long n) {
        long long steps = 0;

        while (prefix <= n) {
            steps += min(next, n + 1) - prefix;
            prefix *= 10;
            next *= 10;
        }

        return steps;
    }

    int findKthNumber(int n, int k) {
        long long curr = 1;
        k--;

        while (k > 0) {
            long long steps = count(curr, curr + 1, n);

            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k--;
            }
        }

        return (int)curr;
    }
};

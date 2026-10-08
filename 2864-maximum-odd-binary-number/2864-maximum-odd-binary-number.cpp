class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;

        // Count number of 1s
        for (char c : s) {
            if (c == '1') {
                ones++;
            }
        }

        int zeros = s.length() - ones;

        string ans;

        // Put remaining 1s at the beginning
        for (int i = 0; i < ones - 1; i++) {
            ans += '1';
        }

        // Put all zeros in the middle
        for (int i = 0; i < zeros; i++) {
            ans += '0';
        }

        // Put one 1 at the end to make it odd
        ans += '1';

        return ans;
    }
};
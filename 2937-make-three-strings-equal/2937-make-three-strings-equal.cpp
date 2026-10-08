class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int i = 0;
        int n = min({s1.length(), s2.length(), s3.length()});

        // common prefix
        while (i < n && s1[i] == s2[i] && s2[i] == s3[i]) {
            i++;
        }

        // No common prefix
        if (i == 0) {
            return -1;
        }

        // Number of deletions required
        return (s1.length() - i) +
               (s2.length() - i) +
               (s3.length() - i);
    }
};
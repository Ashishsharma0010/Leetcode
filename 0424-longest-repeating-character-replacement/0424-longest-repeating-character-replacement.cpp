class Solution {
public:
    int characterReplacement(string s, int k) {

        int hash[26] = {0};

        int l = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {

            hash[s[r] - 'A']++;

            maxFreq = max(maxFreq, hash[s[r] - 'A']);

            int changes = (r - l + 1) - maxFreq;

            while (changes > k) {
                hash[s[l] - 'A']--;
                l++;

                changes = (r - l + 1) - maxFreq;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

class Solution {
public:
    int maxVowels(string s, int k) {

        int n = s.size();
        int count = 0;
        int ans = 0;

        // Count vowels in the first window
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' ||
                s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                count++;
            }
        }

        ans = count;

        // Slide the window
        for (int i = k; i < n; i++) {

            // Remove outgoing character
            if (s[i - k] == 'a' || s[i - k] == 'e' ||
                s[i - k] == 'i' || s[i - k] == 'o' ||
                s[i - k] == 'u') {
                count--;
            }

            // Add incoming character
            if (s[i] == 'a' || s[i] == 'e' ||
                s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                count++;
            }

            ans = max(ans, count);

            // Maximum possible answer is k
            if (ans == k) {
                return k;
            }
        }

        return ans;
    }
};

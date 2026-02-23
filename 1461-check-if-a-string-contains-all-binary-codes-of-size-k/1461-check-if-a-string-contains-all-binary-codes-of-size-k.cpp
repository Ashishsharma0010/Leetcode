class Solution {
public:
    bool hasAllCodes(string s, int k) {
                int n = s.size();

        // If string is too short
        if (n < k) return false;

        int need = 1 << k;   // Total possible binary codes
        vector<bool> seen(need, false);

        int mask = need - 1; // Keeps last k bits
        int num = 0;         // Current window value
        int count = 0;       // Number of unique codes found

        for (int i = 0; i < n; i++) {
            // Shift left and add new bit
            num = ((num << 1) & mask) | (s[i] - '0');

            // Start checking only after first k characters
            if (i >= k - 1) {
                if (!seen[num]) {
                    seen[num] = true;
                    count++;

                    // If all codes found
                    if (count == need)
                        return true;
                }
            }
        }

        return false;
        
    }
};
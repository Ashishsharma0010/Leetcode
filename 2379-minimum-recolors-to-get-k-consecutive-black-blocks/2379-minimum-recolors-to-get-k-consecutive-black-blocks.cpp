
class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int n = blocks.size();
        int white = 0;
        int ans = INT_MAX;

        // Count white blocks in the first window
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                white++;
            }
        }

        ans = white;

        // Slide the window
        for (int i = k; i < n; i++) {

            // Remove the outgoing character
            if (blocks[i - k] == 'W') {
                white--;
            }

            // Add the incoming character
            if (blocks[i] == 'W') {
                white++;
            }

            ans = min(ans, white);
        }

        return ans;
    }
};

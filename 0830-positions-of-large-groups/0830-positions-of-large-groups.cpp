class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;

        int n = s.size();
        int i = 0;

        while (i < n) {
            int j = i;

            // Find the end of the current group
            while (j < n && s[j] == s[i]) {
                j++;
            }

            // Group length = j - i
            if (j - i >= 3) {
                ans.push_back({i, j - 1});
            }

            // Move to the next group
            i = j;
        }

        return ans;
    }
};
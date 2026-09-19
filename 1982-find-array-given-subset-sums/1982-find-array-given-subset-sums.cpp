class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end());
        vector<int> ans;
        while (n--) {
            int d = sums[1] - sums[0];
            unordered_map<int, int> cnt;
            for (int x : sums) cnt[x]++;
            vector<int> left, right;
            bool zeroInLeft = false;
            for (int x : sums) {
                if (cnt[x] == 0) continue;
                cnt[x]--;
                cnt[x + d]--;
                left.push_back(x);
                right.push_back(x + d);
                if (x == 0) zeroInLeft = true;
            }
            if (zeroInLeft) {
                ans.push_back(d);
                sums = left;
            } else {
                ans.push_back(-d);
                sums = right;
            }
        }
        return ans;
    }
};
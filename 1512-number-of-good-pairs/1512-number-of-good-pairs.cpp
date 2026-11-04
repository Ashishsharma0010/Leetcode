
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        vector<int> freq(101, 0);
        int ans = 0;

        for (int num : nums) {

            ans += freq[num];

            freq[num]++;
        }

        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};
        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            int begin = (i > 0 && nums[i] == nums[i - 1]) ? start : 0;
            start = res.size();
            for (int j = begin; j < start; j++) {
                vector<int> sub = res[j];
                sub.push_back(nums[i]);
                res.push_back(sub);
            }
        }
        return res;
    }
};
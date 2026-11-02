class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        for (auto& row : grid) {
            for (int num : row) {
                nums.push_back(num);
            }
        }

        int base = nums[0];

        for (int num : nums) {
            if ((num - base) % x != 0) {
                return -1;
            }
        }

        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2];
        int operations = 0;

        for (int num : nums) {
            operations += abs(num - median) / x;
        }

        return operations;
    }
};
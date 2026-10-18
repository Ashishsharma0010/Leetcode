class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int leftMax = nums[0];
        int currMax = nums[0];
        int partition = 1;

        for (int i = 1; i < nums.size(); i++) {
            currMax = max(currMax, nums[i]);

            if (nums[i] < leftMax) {
                leftMax = currMax;
                partition = i + 1;
            }
        }

        return partition;
    }
};
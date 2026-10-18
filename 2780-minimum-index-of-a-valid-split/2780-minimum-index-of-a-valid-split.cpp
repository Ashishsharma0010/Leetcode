class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        // Find the dominant element using Boyer-Moore
        int candidate = 0, count = 0;

        for (int x : nums) {
            if (count == 0) {
                candidate = x;
            }

            if (x == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // Count total occurrences of the dominant element
        int total = 0;
        for (int x : nums) {
            if (x == candidate) {
                total++;
            }
        }

        int leftCount = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == candidate) {
                leftCount++;
            }

            int leftSize = i + 1;
            int rightSize = n - leftSize;
            int rightCount = total - leftCount;

            if (leftCount * 2 > leftSize &&
                rightCount * 2 > rightSize) {
                return i;
            }
        }

        return -1;
    }
};
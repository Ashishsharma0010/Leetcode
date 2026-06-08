class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, eq, greater;
        for (int x : nums) {
            if (x < pivot) less.push_back(x);
            else if (x == pivot) eq.push_back(x);
            else greater.push_back(x);
        }
        less.insert(less.end(), eq.begin(), eq.end());
        less.insert(less.end(), greater.begin(), greater.end());
        return less;
    }
};
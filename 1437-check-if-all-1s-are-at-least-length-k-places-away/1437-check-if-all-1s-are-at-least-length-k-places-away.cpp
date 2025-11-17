class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
    int zeros = k; // treat as if we have already seen k zeros before start
        int prev = -1; // index of last seen 1; -1 means none seen yet
          for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] == 1) {
                 if (prev != -1) {
            // number of zeros between prev and i is (i - prev - 1)
                 if (i - prev - 1 < k) return false;
            }
                prev = i;
                       }
          }
                                                                                                                   return true;
        
    }
};
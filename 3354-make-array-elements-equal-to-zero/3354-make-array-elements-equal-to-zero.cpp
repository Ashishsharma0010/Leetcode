class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
                int res = 0;

                        for (int start = 0; start < n; ++start) {
                                    if (nums[start] != 0) continue;

                                                for (int dir : {-1, 1}) {
                                                                vector<int> a(nums); // copy array once per (zero, direction)
                                                                                int i = start, d = dir;

                                                                                                while (i >= 0 && i < n) {
                                                                                                                    if (a[i] == 0) {
                                                                                                                                            i += d;
                                                                                                                                                                } else {
                                                                                                                                                                                        --a[i];
                                                                                                                                                                                                                d = -d;
                                                                                                                                                                                                                                        i += d;
                                                                                                                                                                                                                                                            }

                                                                                                                                                                                                                                                                                // Optimization: if max(a) == 0 early, break
                                                                                                                                                                                                                                                                                                    if (all_of(a.begin(), a.end(), [](int x){ return x == 0; })) {
                                                                                                                                                                                                                                                                                                                            res++;
                                                                                                                                                                                                                                                                                                                                                    break;
                                                                                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                                                                                                    return res;
        
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<int>& nums, int l, int r) {
            while (l <= r && nums[l] == 0) l++;
                    while (r >= l && nums[r] == 0) r--;
                            if (l > r) return 0;
                                    int mn = INT_MAX;
                                            for (int i = l; i <= r; i++)
                                                        if (nums[i] > 0) mn = min(mn, nums[i]);
                                                                for (int i = l; i <= r; i++)
                                                                            if (nums[i] > 0) nums[i] -= mn;
                                                                                    int res = 1;
                                                                                            int start = l;
                                                                                                    while (start <= r) {
                                                                                                                while (start <= r && nums[start] == 0) start++;
                                                                                                                            int end = start;
                                                                                                                                        while (end <= r && nums[end] != 0) end++;
                                                                                                                                                    res += dfs(nums, start, end - 1);
                                                                                                                                                                start = end;
                                                                                                                                                                        }
                                                                                                                                                                                return res;
                                                                                                                                                                                    }

                                                                                                                                                                                        int minOperations(vector<int>& nums) {
                                                                                                                                                                                                return dfs(nums, 0, nums.size() - 1);
                                                                                                                                                                                                    }
                                                                                                                                                                                                    };
                                                                                                                                                                                                    
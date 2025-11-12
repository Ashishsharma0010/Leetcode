class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
                
                        // Step 1: Check overall GCD
                                int overall_gcd = nums[0];
                                        for (int i = 1; i < n; ++i)
                                                    overall_gcd = gcd(overall_gcd, nums[i]);
                                                            
                                                                    if (overall_gcd > 1)
                                                                                return -1;

                                                                                        // Step 2: If any 1 exists
                                                                                                int ones = count(nums.begin(), nums.end(), 1);
                                                                                                        if (ones > 0)
                                                                                                                    return n - ones;

                                                                                                                            // Step 3: Find the shortest subarray with GCD = 1
                                                                                                                                    int min_len = INT_MAX;
                                                                                                                                            for (int i = 0; i < n; ++i) {
                                                                                                                                                        int curr_gcd = nums[i];
                                                                                                                                                                    for (int j = i + 1; j < n; ++j) {
                                                                                                                                                                                    curr_gcd = gcd(curr_gcd, nums[j]);
                                                                                                                                                                                                    if (curr_gcd == 1) {
                                                                                                                                                                                                                        min_len = min(min_len, j - i + 1);
                                                                                                                                                                                                                                            break; // No need to go further
                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                                        // Step 4: Result
                                                                                                                                                                                                                                                                                                return (min_len - 1) + (n - 1);
        
    }
};
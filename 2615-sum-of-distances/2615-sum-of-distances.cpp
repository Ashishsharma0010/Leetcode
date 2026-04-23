class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);
        
        // Group indices by value
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[nums[i]].push_back(i);
        }
        
        for (auto& [val, indices] : groups) {
            int m = indices.size();
            if (m == 1) continue; // arr[i] stays 0
            
            // Build prefix sums of indices
            vector<long long> prefix(m + 1, 0);
            for (int j = 0; j < m; j++) {
                prefix[j + 1] = prefix[j] + indices[j];
            }
            
            long long total = prefix[m];
            
            for (int j = 0; j < m; j++) {
                long long pos = indices[j];
                
                // Sum of distances to left elements (indices[0..j-1])
                long long left_sum = prefix[j];           // sum of left indices
                long long left_count = j;
                long long left_contrib = pos * left_count - left_sum;
                
                // Sum of distances to right elements (indices[j+1..m-1])
                long long right_sum = total - prefix[j + 1]; // sum of right indices
                long long right_count = m - j - 1;
                long long right_contrib = right_sum - pos * right_count;
                
                arr[indices[j]] = left_contrib + right_contrib;
            }
        }
        
        return arr;
    }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
    
        }
        vector<int> ans;
        for(auto freq:mp){
            if(freq.second>nums.size()/3){
                ans.push_back(freq.first);
            }
        }
        return ans;
        
    }
};
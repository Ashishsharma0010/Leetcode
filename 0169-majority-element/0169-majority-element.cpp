class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int,int> mp;
       for(auto it:nums){
        mp[it]++;
       }
       for(auto s:mp){
        if(s.second>nums.size()/2){
            return s.first;
        }
         
       }
       return -1;
    }
};
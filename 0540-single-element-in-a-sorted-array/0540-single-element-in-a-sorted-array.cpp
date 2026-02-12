class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> s;
        for(auto &it:nums){
            s[it]++;
        }
        for(auto &itt:s){
        if(itt.second==1){
            return itt.first;
        }
        }
        return -1;
        
    }
};
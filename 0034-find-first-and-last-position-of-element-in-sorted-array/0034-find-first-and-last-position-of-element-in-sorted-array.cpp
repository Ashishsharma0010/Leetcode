class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Now i am trying to do by using the brute force method  by time complexity O(N) AND SPACE O(1)
        vector<int> s(2,-1);
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==target){
                if(s[0]==-1){
                    s[0]=i;

                }
                s[1]=i;  // s[i] update kar diya maine s[0] se s[1]; next time s[1]==-1 
            }
        }
        return s; // last m return krdiya jo value aai hai

    }
};
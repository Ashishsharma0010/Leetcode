class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // brute force because they said time complexity should be O(LOG N)AND  i am doing in O(N)
        int n=nums.size();
        int peak;
        for(int i=0; i<n; i++){
            if((i==0 || nums[i-1]<nums[i]) && (i==n-1 || nums[i+1]<nums[i]))
            return i;
            
        }
        return -1;
        
    }
};
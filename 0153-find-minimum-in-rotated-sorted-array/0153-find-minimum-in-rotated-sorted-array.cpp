class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=INT_MAX;
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=(int(start+end)/2);
            if(nums[start]<=nums[mid]){
                ans=min(ans,nums[start]);
                start=mid+1;
            }
            else{
                end=mid-1;
                ans=min(ans,nums[mid]);
            }
        }
        return ans;
        
    }
};
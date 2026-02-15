class Solution {
public:
    int findMin(vector<int>& nums) {
        
        //TIME COMPLEXITY OF THIS O(LOG N);
        //SPACE COMPLEXITY OF THIS O(1);
        int ans=INT_MAX;
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2;

            if(nums[mid]>=nums[start]){
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
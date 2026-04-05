class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
     if(n==0){
         cout<<"0";
     }
     int left=0;
     for(int right=0; right<n; right++){
         if(nums[right]!=0){
             swap(nums[right],nums[left]);
              left++;
         }
         
     }
     for(auto x: nums){
        cout<<x<<" ";
     }
        
    }
};
class Solution {
public:
    
       int mySqrt(int n) {
        if(n==0)return 0;if(n==1)return 1;
        int ans=-1;
        int start=1;int end=n/2;
        while(start<=end){
            long mid=start+(end-start)/2;
            if(mid*mid<=n){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
         int sum=0;
         for(int i=0; i<k; i++){
            sum=sum+cardPoints[i];
         }
         int ans=sum;
         int right=n-1;
         for(int i=k-1; i>=0; i--){
            sum=sum-cardPoints[i];
            sum=sum+cardPoints[right];
            right--;
            ans=max(ans,sum);

         }
        return  ans;
    }
};
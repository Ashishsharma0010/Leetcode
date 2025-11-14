class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> count(101);
        int maxfre=0;
        int total=0;
        for(auto &mu: nums){
           count[mu]++;
           int fre=count[mu];
           if(fre > maxfre){
            maxfre=fre;
            total=maxfre;
           }else if(fre==maxfre){
            total=total+maxfre;
           }
        }
        return total;
       
        
    }
};
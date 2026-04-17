class Solution {
public:
    double myPow(double x, int n) {
        if(x==0){
            return 0;
        }
        double ans=pow(x,n);
        return ans;
        
    }
};
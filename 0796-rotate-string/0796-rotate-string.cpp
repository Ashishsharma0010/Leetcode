class Solution {
public:
    bool rotateString(string s, string goal) {
        int a=s.size();
        int b=goal.size();
        if(a!=b){
            return false;
        }
        if(s==goal){
            return true;
        }
        for(int i=1; i<a; i++){
            rotate(s.begin(),s.begin()+1,s.end());
            if(s==goal){
                return true;
            }
        }
        return false;
        // time complexity will be O(N^2) Kyuki ek for loop lgra h or fir ek roatet kr rhe h  n time isliye 
        // Space complexity will be O(1)
        
    }
};
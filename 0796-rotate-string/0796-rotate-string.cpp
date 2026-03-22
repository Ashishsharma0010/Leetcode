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
        if((s+s).find(goal)!=string::npos){
            return true;
        }
        return false;
        
    }
};
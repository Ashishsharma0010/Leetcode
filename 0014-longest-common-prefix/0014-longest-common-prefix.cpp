class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0){
            return "";
        }
        string ans="";
        sort(strs.begin(), strs.end());
        int i=0;
        while(i<strs[0].length() && strs[0][i]==strs[n-1][i]){
            ans=ans+strs[0][i];
            i++;
        }
        return ans;
        
    }
};
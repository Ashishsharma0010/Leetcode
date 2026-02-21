class Solution {
public: 
    bool  alphanumric(char ch){
         
         if((ch>='0' && ch<='9') || (tolower(ch)>='a' && tolower(ch)<='z')){
            return true;
         }
         return false;

    }
    bool isPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
        while(start<=end){
            if(!alphanumric(s[start])){
                start++;
                continue;
            }
            if(!alphanumric(s[end])){
                end--;
                continue;
            }
            if(tolower(s[start])!=tolower(s[end])){            return false;
            }
            start++;
            end--;

        }
        return true;
        
    }
};
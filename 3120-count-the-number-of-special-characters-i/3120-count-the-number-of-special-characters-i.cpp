class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> lower;
        set<char> upper;
        for(auto ch : word){
            if(ch>='a' && ch<='z'){
                lower.insert(ch);
            }
            else {
                upper.insert(ch);
            }
    
        }
        int count=0;
        for(char ch='a'; ch<='z'; ch++){
          if(lower.count(ch) && upper.count(ch-32))  // we use count in set to find the char;
          count++;
        }


        return count;

    
        
    }
};
class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1));
        if (k > total) return "";
        
        string result = "";
        k--;
        
        int branchSize = 1 << (n - 1);
        result += ('a' + k / branchSize);
        k %= branchSize;
        
        for (int i = 1; i < n; i++) {
            branchSize >>= 1;
            
            string candidates = "";
            for (char c : {'a', 'b', 'c'})
                if (c != result.back()) candidates += c;
            
            result += candidates[k / branchSize];
            k %= branchSize;
        }
        
        return result;
    }
};
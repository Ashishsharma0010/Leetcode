class Solution {
public:
    unordered_map<string, int> memo;
    
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        
        string key = s1 + "#" + s2;
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;
        
        int n = s1.size();
        
        int count[26] = {0};
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                memo[key] = false;
                return false;
            }
        }
        
        for (int i = 1; i < n; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {
                memo[key] = true;
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                memo[key] = true;
                return true;
            }
        }
        
        memo[key] = false;
        return false;
    }
};
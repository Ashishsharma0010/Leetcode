class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char, int> count;

        for (char letter : s) count[letter]++;
        
        int result = 0;
        bool placece = false;

        for (auto& [letter, total] : count) {
            result += (total / 2) * 2;
            if (total % 2 == 1) placece = true;
        }
        
        return result + (placece ? 1 : 0);
    }
};
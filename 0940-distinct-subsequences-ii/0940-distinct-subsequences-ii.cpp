class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> end(26, 0);
        long long total = 0;
        
        for (char ch : s) {
            int c = ch - 'a';
            long long newVal = (total + 1) % MOD;
            total = (total - end[c] + newVal + MOD) % MOD;
            end[c] = newVal;
        }
        
        return (int)(total % MOD);
    }
};
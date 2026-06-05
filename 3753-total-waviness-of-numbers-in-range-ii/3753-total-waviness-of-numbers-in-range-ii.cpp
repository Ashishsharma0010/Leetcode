class Solution {
    string s;
    map<tuple<int,int,int,int,int>, pair<long long,long long>> memo;
    
    pair<long long,long long> dp(int pos, int prev, int pprev, int tight, int started) {
        if (pos == (int)s.size()) return {1, 0};
        
        auto key = make_tuple(pos, prev, pprev, tight, started);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;
        
        int limit = tight ? (s[pos]-'0') : 9;
        long long total_cnt = 0, total_wav = 0;
        
        for (int d = 0; d <= limit; d++) {
            int new_tight = tight && (d == limit);
            if (!started && d == 0) {
                auto [cnt, wav] = dp(pos+1, -1, -1, new_tight, 0);
                total_cnt += cnt;
                total_wav += wav;
            } else {
                long long added = 0;
                if (started && pprev != -1 && prev != -1) {
                    if (prev > pprev && prev > d) added = 1;
                    else if (prev < pprev && prev < d) added = 1;
                }
                auto [cnt, wav] = dp(pos+1, d, prev, new_tight, 1);
                total_cnt += cnt;
                total_wav += wav + added * cnt;
            }
        }
        return memo[key] = {total_cnt, total_wav};
    }
    
    long long solve(long long n) {
        if (n <= 0) return 0;
        s = to_string(n);
        memo.clear();
        return dp(0, -1, -1, 1, 0).second;
    }
    
public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
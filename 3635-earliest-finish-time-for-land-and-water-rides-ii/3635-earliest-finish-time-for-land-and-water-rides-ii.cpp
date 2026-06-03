class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int best = INT_MAX;
        
        auto check = [&](vector<int>& aStart, vector<int>& aDur, vector<int>& bStart, vector<int>& bDur) {
            int sz = bStart.size();
            vector<int> order(sz);
            iota(order.begin(), order.end(), 0);
            sort(order.begin(), order.end(), [&](int x, int y){
                return bStart[x] < bStart[y];
            });
            
            vector<int> bs(sz), bf(sz), bd(sz);
            for (int i = 0; i < sz; i++) {
                bs[i] = bStart[order[i]];
                bd[i] = bDur[order[i]];
                bf[i] = bs[i] + bd[i];
            }
            
            vector<int> suf(sz + 1, INT_MAX);
            for (int i = sz - 1; i >= 0; i--)
                suf[i] = min(suf[i + 1], bf[i]);
            
            vector<int> pre(sz + 1, INT_MAX);
            for (int i = 0; i < sz; i++)
                pre[i + 1] = min(pre[i], bd[i]);
            
            int n = aStart.size();
            for (int i = 0; i < n; i++) {
                int done = aStart[i] + aDur[i];
                
                int lo = 0, hi = sz;
                while (lo < hi) {
                    int mid = (lo + hi) / 2;
                    if (bs[mid] >= done) hi = mid;
                    else lo = mid + 1;
                }
                
                if (lo < sz && suf[lo] != INT_MAX)
                    best = min(best, suf[lo]);
                
                if (lo > 0 && pre[lo] != INT_MAX)
                    best = min(best, done + pre[lo]);
            }
        };
        
        check(landStartTime, landDuration, waterStartTime, waterDuration);
        check(waterStartTime, waterDuration, landStartTime, landDuration);
        
        return best;
    }
};

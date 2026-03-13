class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        auto maxHeightReduction = [](long long T, long long w) -> long long {
            long long ratio = T / w;
            long long lo = 0, hi = 200000;
            while (lo < hi) {
                long long mid = lo + (hi - lo + 1) / 2;
                if (mid * (mid + 1) / 2 <= ratio)
                    lo = mid;
                else
                    hi = mid - 1;
            }
            return lo;
        };
        
        auto canFinish = [&](long long T) -> bool {
            long long totalReduction = 0;
            for (int w : workerTimes) {
                totalReduction += maxHeightReduction(T, w);
                if (totalReduction >= mountainHeight) return true;
            }
            return totalReduction >= mountainHeight;
        };
        
        long long lo = 1;
        long long hi = (long long)(*max_element(workerTimes.begin(), workerTimes.end())) 
                       * mountainHeight * (mountainHeight + 1) / 2;
        
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (canFinish(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        
        return lo;
    }
};
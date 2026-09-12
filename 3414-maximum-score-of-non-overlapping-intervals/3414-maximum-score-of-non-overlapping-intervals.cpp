class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int a, int b){
            return intervals[a][1] < intervals[b][1];
        });

        vector<long long> lArr(n), rArr(n), wArr(n);
        vector<int> origIdx(n);
        for (int i = 0; i < n; i++) {
            int id = ord[i];
            lArr[i] = intervals[id][0];
            rArr[i] = intervals[id][1];
            wArr[i] = intervals[id][2];
            origIdx[i] = id;
        }

        struct Node {
            long long score = 0;
            vector<int> idx;
        };

        vector<array<Node,5>> dp(n + 1);
        for (int k = 0; k <= 4; k++) dp[0][k] = Node{0, {}};

        auto better = [](const Node& a, const Node& b) -> bool {
            if (a.score != b.score) return a.score > b.score;
            return a.idx < b.idx; 
        };

        for (int i = 1; i <= n; i++) {
            int cur = i - 1;
            long long l = lArr[cur];
            int p = lower_bound(rArr.begin(), rArr.end(), l) - rArr.begin();

            for (int k = 0; k <= 4; k++) {
                Node best = dp[i - 1][k]; 
                if (k >= 1) {
                    Node cand = dp[p][k - 1];
                    cand.score += wArr[cur];
                    cand.idx.push_back(origIdx[cur]);
                    sort(cand.idx.begin(), cand.idx.end());
                    if (better(cand, best)) best = cand;
                }
                dp[i][k] = best;
            }
        }

        return dp[n][4].idx;
    }
};
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slopeCount;
            int duplicate = 0;
            int best = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicate++;
                    continue;
                }

                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                // Normalize slope direction.
                if (dx == 0) {
                    dy = 1;  // Vertical line
                } else if (dy == 0) {
                    dx = 1;  // Horizontal line
                } else if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }

                string slope = to_string(dy) + "/" + to_string(dx);
                slopeCount[slope]++;
                best = max(best, slopeCount[slope]);
            }

            ans = max(ans, best + duplicate + 1);
        }

        return ans;
    }
};
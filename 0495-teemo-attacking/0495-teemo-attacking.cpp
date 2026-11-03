
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {

        int total = 0;
        int n = timeSeries.size();

        for (int i = 0; i < n - 1; i++) {
            int gap = timeSeries[i + 1] - timeSeries[i];

            total += min(gap, duration);
        }

        // Add the full duration of the last attack
        total += duration;

        return total;
    }
};

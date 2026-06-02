class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size(), m = waterStartTime.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int land_end = landStartTime[i] + landDuration[i];
                ans = min(ans, max(land_end, waterStartTime[j]) + waterDuration[j]);
                
                int water_end = waterStartTime[j] + waterDuration[j];
                ans = min(ans, max(water_end, landStartTime[i]) + landDuration[i]);
            }
        }
        
        return ans;
    }
};
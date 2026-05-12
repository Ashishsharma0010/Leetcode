class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) {
            return (a[1] - a[0]) < (b[1] - b[0]);
        });

        int energy = 0;
        for (auto& task : tasks) {
            energy = max(task[1], energy + task[0]);
        }

        return energy;
    }
};
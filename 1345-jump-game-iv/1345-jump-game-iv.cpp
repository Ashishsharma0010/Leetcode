class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++)
            graph[arr[i]].push_back(i);

        vector<bool> visited(n, false);
        visited[0] = true;
        queue<pair<int,int>> q;
        q.push({0, 0});

        while (!q.empty()) {
            auto [idx, steps] = q.front();
            q.pop();

            vector<int> neighbors = {idx - 1, idx + 1};
            if (graph.count(arr[idx]))
                for (int j : graph[arr[idx]])
                    neighbors.push_back(j);

            graph.erase(arr[idx]);

            for (int nxt : neighbors) {
                if (nxt == n - 1) return steps + 1;
                if (nxt >= 0 && nxt < n && !visited[nxt]) {
                    visited[nxt] = true;
                    q.push({nxt, steps + 1});
                }
            }
        }

        return -1;
    }
};
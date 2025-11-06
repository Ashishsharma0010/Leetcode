class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> parent(c + 1), size(c + 1, 1);
                iota(parent.begin(), parent.end(), 0);

                        function<int(int)> find = [&](int x) {
                                    return parent[x] == x ? x : parent[x] = find(parent[x]);
                                            };

                                                    auto unite = [&](int a, int b) {
                                                                a = find(a);
                                                                            b = find(b);
                                                                                        if (a == b) return;
                                                                                                    if (size[a] < size[b]) swap(a, b);
                                                                                                                parent[b] = a;
                                                                                                                            size[a] += size[b];
                                                                                                                                    };

                                                                                                                                            for (auto &e : connections) unite(e[0], e[1]);

                                                                                                                                                    unordered_map<int, set<int>> grid;
                                                                                                                                                            for (int i = 1; i <= c; i++) grid[find(i)].insert(i);

                                                                                                                                                                    vector<bool> online(c + 1, true);
                                                                                                                                                                            vector<int> ans;

                                                                                                                                                                                    for (auto &q : queries) {
                                                                                                                                                                                                int type = q[0], x = q[1];
                                                                                                                                                                                                            int p = find(x);
                                                                                                                                                                                                                        if (type == 1) {
                                                                                                                                                                                                                                        if (online[x]) ans.push_back(x);
                                                                                                                                                                                                                                                        else ans.push_back(grid[p].empty() ? -1 : *grid[p].begin());
                                                                                                                                                                                                                                                                    } else {
                                                                                                                                                                                                                                                                                    if (online[x]) {
                                                                                                                                                                                                                                                                                                        online[x] = false;
                                                                                                                                                                                                                                                                                                                            grid[p].erase(x);
                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                                                                                                                        return ans;
        
        
    }
};
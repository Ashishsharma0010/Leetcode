
class Solution {
public:
    int containVirus(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int totalWalls = 0;

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while (true) {

            vector<vector<pair<int,int>>> regions;
            vector<unordered_set<int>> threats;
            vector<int> walls;

            vector<vector<bool>> visited(m, vector<bool>(n, false));

            // Find all infected regions
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {

                    if (grid[i][j] != 1 || visited[i][j])
                        continue;

                    vector<pair<int,int>> cells;
                    unordered_set<int> threatened;
                    int wallCount = 0;

                    function<void(int,int)> dfs = [&](int x, int y) {

                        visited[x][y] = true;
                        cells.push_back({x, y});

                        for (int d = 0; d < 4; d++) {

                            int nx = x + dx[d];
                            int ny = y + dy[d];

                            if (nx < 0 || ny < 0 ||
                                nx >= m || ny >= n)
                                continue;

                            if (grid[nx][ny] == 0) {
                                wallCount++;

                                threatened.insert(nx * n + ny);
                            }
                            else if (grid[nx][ny] == 1 &&
                                     !visited[nx][ny]) {

                                dfs(nx, ny);
                            }
                        }
                    };

                    dfs(i, j);

                    regions.push_back(cells);
                    threats.push_back(threatened);
                    walls.push_back(wallCount);
                }
            }

            // Find the most dangerous region
            if (regions.empty())
                break;

            int maxIndex = -1;
            int maxThreats = 0;

            for (int i = 0; i < threats.size(); i++) {
                if ((int)threats[i].size() > maxThreats) {
                    maxThreats = threats[i].size();
                    maxIndex = i;
                }
            }

            // No more cells can be infected
            if (maxThreats == 0)
                break;

            // Quarantine the most dangerous region
            totalWalls += walls[maxIndex];

            for (auto &cell : regions[maxIndex]) {
                grid[cell.first][cell.second] = -1;
            }

            // Spread virus from all other regions
            for (int i = 0; i < regions.size(); i++) {

                if (i == maxIndex)
                    continue;

                for (int id : threats[i]) {
                    int x = id / n;
                    int y = id % n;

                    grid[x][y] = 1;
                }
            }
        }

        return totalWalls;
    }
};

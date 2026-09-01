class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int litterCount = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        int fullMask = (1 << litterCount) - 1;

        // best[r][c][mask] = maximum energy with which
        // we have reached (r,c) having collected mask.
        vector<vector<vector<short>>> best(
            m,
            vector<vector<short>>(
                n,
                vector<short>(1 << litterCount, -1)
            )
        );

        struct State {
            int r, c, e, mask;
        };

        queue<State> q;

        best[sr][sc][0] = energy;
        q.push({sr, sc, energy, 0});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, e, mask] = q.front();
                q.pop();

                if (mask == fullMask)
                    return moves;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Can't move without energy.
                    if (e == 0)
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter.
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    // Reset energy.
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    // Dominance optimization:
                    // If we've reached the same position with
                    // the same litter mask and >= energy,
                    // this state is useless.
                    if (best[nr][nc][nmask] >= ne)
                        continue;

                    best[nr][nc][nmask] = ne;

                    q.push({nr, nc, ne, nmask});
                }
            }

            moves++;
        }

        return -1;
    }
};
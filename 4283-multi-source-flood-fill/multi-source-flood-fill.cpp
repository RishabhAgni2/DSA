class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));

        queue<pair<int,int>> q;

        // Step 1: initialize
        for (auto &s : sources) {
            int r = s[0], c = s[1], color = s[2];
            grid[r][c] = color;
            time[r][c] = 0;
            q.push({r, c});
        }

        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        // Step 2: BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto &d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

                // first time visit
                if (time[nr][nc] > time[r][c] + 1) {
                    time[nr][nc] = time[r][c] + 1;
                    grid[nr][nc] = grid[r][c];
                    q.push({nr, nc});
                }
                // same time arrival
                else if (time[nr][nc] == time[r][c] + 1) {
                    grid[nr][nc] = max(grid[nr][nc], grid[r][c]);
                }
            }
        }

        return grid;
    }
};
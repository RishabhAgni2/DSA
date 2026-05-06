class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int n = boxGrid.size();
        int m = boxGrid[0].size();

        // store counts separately
        vector<vector<int>> cnt(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {

            int start = 0;

            for (int j = 0; j < m; j++) {

                if (boxGrid[i][j] == '#') {

                    start++;
                    cnt[i][j] = start;
                }
                else if (boxGrid[i][j] == '.') {

                    cnt[i][j] = start;
                }
                else {

                    start = 0;
                }
            }
        }

        vector<vector<char>> Ans(m, vector<char>(n));

        for (int j = 0; j < n; j++) {

            bool start = false;
            int c = 0;

            for (int i = m - 1; i >= 0; i--) {

                if (boxGrid[j][i] == '*') {

                    start = false;
                    c = 0;

                    Ans[i][n - 1 - j] = '*';
                }
                else {

                    if (!start) {

                        start = true;
                        c = cnt[j][i];
                    }

                    if (c > 0) {

                        Ans[i][n - 1 - j] = '#';
                        c--;
                    }
                    else {

                        Ans[i][n - 1 - j] = '.';
                    }
                }
            }
        }

        return Ans;
    }
};
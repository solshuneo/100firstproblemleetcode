class Solution {
    public:
        const int RIGHT = 0;
        const int LEFT = -1;
        const int UP = 2;
        const int DOWN = 3;
        vector<int> spiralOrder(vector<vector<int>>& mtr) {
            int n = mtr.size();
            int m = mtr[0].size();
            vector<vector<int>> matrix(n, vector<int>(m, 0));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    matrix[i][j] = 0;
                }
            }
            int x = 0, y = 0;
            int dir = RIGHT;
            vector<int> ans;
            for (int i = 0; i < n*m; ++i) {
                matrix[x][y] = i + 1;
                ans.emplace_back(mtr[x][y]);
                if (dir == RIGHT) {
                    if (y + 1 < m && matrix[x][y+1] == 0) ++y;
                    else {
                        dir = DOWN;
                    }
                }
                if (dir == DOWN) {
                    if (x + 1 < n && matrix[x+1][y] == 0) x++;
                    else {
                        dir = LEFT;
                    }
                }
                if (dir == LEFT) {
                    if (y - 1 >= 0 && matrix[x][y-1] == 0) --y;
                    else {
                        dir = UP;
                    }
                }
                if (dir == UP) {
                    if (x - 1 >= 0 && matrix[x-1][y] == 0) --x;
                    else {
                        dir = RIGHT;
                        if (dir == RIGHT) {
                            if (y + 1 < m && matrix[x][y+1] == 0) ++y;
                            else {
                                dir = DOWN;
                            }
                        }
                    }
                }
            }
            return ans;
        }
    };
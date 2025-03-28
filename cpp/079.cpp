class Solution {
    public:
        const int dx[4] = {0, 0, -1, 1};
        const int dy[4] = {1, -1, 0, 0};
        bool dfs(vector<vector<char>>& board, int x, int y, string&word, int idx, int&n, int&m, int marker[10][10]) {
            marker[x][y] = true;
            if (idx == word.size()) return true;
            for (int i = 0; i < 4; ++i) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (newx < 0 || newy < 0 || newx == n || newy == m) continue;
                if (marker[newx][newy]) continue;
                if (board[newx][newy] == word[idx]) {
                    bool res = dfs(board, newx, newy, word, idx + 1, n, m, marker);
                    if (res) return true;
                }
            }
            marker[x][y] = false;
            return false;
        }
        bool exist(vector<vector<char>>& board, string word) {
            int n = board.size();
            if (n == 0) {
                if (word.empty()) return true;
                return false;
            }
            if (word.empty()) {
                return true;
            }
            int m = board[0].size();
            int marker[10][10];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (board[i][j] == word[0]) {
                        bool res = dfs(board, i, j, word, 1, n, m, marker);
                        if (res) {
                            return true;
                        }
                    }
                }
            }
            return false;
    
        }
    };
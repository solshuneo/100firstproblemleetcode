// one test wrong at leetcode
class Solution {
    public:
        bool fillout(vector<vector<char>>& board, set<int> row[], set<int> col[], int idx, const int& n, set<int> block[3][3]) {
            int x = idx / n;
            int y = idx % n;
            if (idx == n*n) {
                return true;
            }
            if (! isdigit(board[x][y])) {
                // cout << board[x][y] << endl;
                // cout << idx << endl;
                // for (auto a : row[x]) {
                //     cout << a << ' ' ;
                // }
                // return false;
                for (int i = 1; i <= n; ++i) {
                    if (row[x].find(i) == row[x].end() && col[y].find(i) == col[y].end() && block[x/3][y/3].find(i) == block[x/3][y/3].end()) {
                        row[x].insert(i);
                        col[y].insert(i);
                        block[x/3][y/3].insert(i);
                        bool res = fillout(board, row, col, idx + 1, n, block);
                        row[x].erase(i);
                        col[y].erase(i);
                        block[x/3][y/3].erase(i);
                        if (res) return true;
                    }
                }
            } else {
                return fillout(board, row, col, idx + 1, n, block);
            }
            return false;
        }
        bool isValidSudoku(vector<vector<char>>& board) {
            const int n = 9;
            set<int> row[n], col[n], block[3][3];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (isdigit(board[i][j])) {
                        block[i/3][j/3].insert(board[i][j] - 48);
                        row[i].insert(board[i][j] - 48);
                        col[j].insert(board[i][j] - 48);
                    }
                }
            }
            return fillout(board, row, col, 0, n, block);
        }
    };
    /*
    [
    [".","8","7","6","5","4","3","2","1"],
    ["2",".",".",".",".",".",".",".","."],
    ["3",".",".",".",".",".",".",".","."],
    ["4",".",".",".",".",".",".",".","."],
    ["5",".",".",".",".",".",".",".","."],
    ["6",".",".",".",".",".",".",".","."],
    ["7",".",".",".",".",".",".",".","."],
    ["8",".",".",".",".",".",".",".","."],
    ["9",".",".",".",".",".",".",".","."]
    ]
    */
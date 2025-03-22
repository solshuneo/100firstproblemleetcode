class Solution {
    public:
        string convert(string s, int numRows) {
            int n = s.size();
            char table[numRows][n];
            for (int i = 0; i < numRows; ++i) {
                for (int j = 0; j < n; ++j) {
                    table[i][j] = 0;
                }
            }
            int sign = 1;
            for (int i = 0, row = 0, id = 0; i < n; ++i) {
                table[row][id] = s[i];
                row += sign;
                if (row == numRows) {
                    row = row - 1 - (numRows != 1);
                    sign = -1;
                    id += 1;
                } else if (row == -1) {
                    row = row + 1 + (numRows != 1);
                    sign = 1;
                    id += 1;
                }
            }
            string ans = "";
            for (int i = 0; i < numRows; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (table[i][j] == 0) continue;
                    ans += table[i][j];
                }
            }
            return ans;
        }
    };
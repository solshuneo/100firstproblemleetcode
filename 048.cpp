class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
            vector<vector<int>> mirror(n, vector<int>(m));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    mirror[j][n-i-1] = matrix[i][j];
                }
            }
            matrix = mirror;
        }
    };
class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> ans;
            for (int i = 1; i <= numRows; ++i) {
                ans.emplace_back(vector<int>(i));
                for (int j = 0; j < i; ++j) {
                    if (j == 0) ans[i-1][j] = 1;
                    else if (j == i-1) ans[i-1][j] = 1;
                    else ans[i-1][j] = ans[i-2][j-1] + ans[i-2][j];
                }
            }
            return ans;
        }
    };
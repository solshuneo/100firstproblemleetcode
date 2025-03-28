class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<vector<int>> ans;
                for (int i = 1; i <= rowIndex + 1; ++i) {
                    ans.emplace_back(vector<int>(i));
                    for (int j = 0; j < i; ++j) {
                        if (j == 0) ans[i-1][j] = 1;
                        else if (j == i-1) ans[i-1][j] = 1;
                        else ans[i-1][j] = ans[i-2][j-1] + ans[i-2][j];
                    }
                }
            if (rowIndex == 0) return vector<int>{1};
            return ans[rowIndex];
        }
    };
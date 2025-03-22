class Solution {
    public:
        void gen(vector<vector<int>> & ans, int n, int k, vector<int>&cur, int last) {
            if (cur.size() == k) {
                ans.emplace_back(cur);
                return ;
            }
            for (int i = last + 1; i <= n; ++i) {
                cur.emplace_back(i);
                gen(ans, n, k, cur, i);
                cur.pop_back();
            }
        }
        vector<vector<int>> combine(int n, int k) {
            vector<vector<int>> ans;
            vector<int> cur;
            gen(ans, n, k, cur, 0);
            return ans;
        }
    };
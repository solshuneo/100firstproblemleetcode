class Solution {
    public:
        void get(vector<vector<int>>&ans, vector<int>& candidates, int target, int total, vector<int>& cur, int above) {
            if (total > target) return ;
            if (total == target) {
                ans.emplace_back(cur);
            }
            for (int x : candidates) {
                if (x < above) continue;
                cur.emplace_back(x);
                get(ans, candidates, target, total + x, cur, x);
                cur.pop_back();
            }
        }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> cur;
            get(ans, candidates, target, 0, cur, 1);
            return ans;
        }
    };
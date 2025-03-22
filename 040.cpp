class Solution {
    public:
        void get(vector<vector<int>>& ans, vector<int>&candidates, int target, vector<int>&cur, int idx) {
            if (target < 0) {
                return ;
            }
            if (target == 0) {
                ans.emplace_back(cur);
                return ;
            }
            int n = candidates.size();
            for (int i = idx; i < n; ++i) {
                if (i > idx && candidates[i] == candidates[i-1]) continue;
                cur.emplace_back(candidates[i]);
                get(ans, candidates, target - candidates[i], cur, i + 1);
                cur.pop_back();
            }
        } 
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int>> ans;
            vector<int> cur;
            get(ans, candidates, target, cur, 0);
            return ans;
        }
    };
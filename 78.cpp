class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> ans;
            for (int i = 0; i < (1<<n); ++i) {
                vector<int> cur;
                for (int j = 0; j < n; ++j) {
                    if ((1<<j) & i) {
                        cur.emplace_back(nums[j]);
                    }
                }
                ans.emplace_back(cur);
            }
            return ans;
        }
    };
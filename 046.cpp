class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            int n = nums.size();
            int idx[11];
            for (int i = 0; i < n; ++i) idx[i] = i;
            vector<vector<int>> ans;
            do {
                vector<int> cur(n);
                for (int i = 0; i < n; ++i) {
                    cur[i] = nums[idx[i]];
                }
                ans.emplace_back(cur);
            } while (next_permutation(idx, idx + n));   
            return ans;
        }
    };
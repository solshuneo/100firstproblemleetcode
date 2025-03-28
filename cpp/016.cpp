class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            int lhs = -3000000;
            int rhs = 3000000;
            int n = nums.size();
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    for (int k = j + 1; k < n; ++k) {
                        int total = nums[i] + nums[j] + nums[k];
                        if (total <= target) lhs = max(total, lhs);
                        if (total >= target) rhs = min(rhs, total);
                    }
                }
            }
            if (lhs == -3000000) return rhs;
            if (rhs == 3000000) return lhs;
            if (target - lhs < rhs - target) return lhs;
            return rhs;
        }
    };
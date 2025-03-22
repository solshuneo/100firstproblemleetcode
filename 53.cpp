class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int best = -1e4 - 10;
            int n = nums.size();
            int local = 0;
            for (int i = 0; i < n; ++i) {
                local = max(nums[i], local + nums[i]);
                best = max(local, best);
            }
            return best;
        }
    };
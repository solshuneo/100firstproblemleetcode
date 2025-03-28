class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {
            int n = nums.size();
            vector<string> ans;
            for (int left = 0, right = 0; right < n; ++right) {
                if (right != n-1 && nums[right] == nums[right+1] - 1) continue;
                if (left == right) {
                    ans.emplace_back(to_string(nums[left]));
                } else {
                    ans.emplace_back(to_string(nums[left]) + "->" + to_string(nums[right]));
                }
                left = right + 1;
            }
            return ans;
        }
    };
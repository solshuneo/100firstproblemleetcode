class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int res = nums.size() - count(nums.begin(), nums.end(), val);     
            vector<int> imposter;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == val) continue;
                imposter.emplace_back(nums[i]);
            }
            nums = imposter;
            return res;
        }
    };
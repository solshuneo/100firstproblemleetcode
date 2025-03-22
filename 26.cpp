class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            vector<int> new_nums;
            int n = nums.size();
            for (int i = 0; i < n; ++i) {
                if (i == 0 || nums[i] != nums[i-1]) {
                    new_nums.emplace_back(nums[i]);
                } 
            }
            nums = new_nums;
            return new_nums.size();
        }
    };
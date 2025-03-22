class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
            vector<int> id(n);
            iota(id.begin(), id.end(), 0);
            sort(id.begin(), id.end(), [&](int i, int j) {
                return nums[i] < nums[j];
            });
            for (int left = 0, right = n-1; left <= right; ) {
                if (nums[id[left]] + nums[id[right]] == target) {
                    return vector<int> {id[left], id[right]};
                }
                if (nums[id[left]] + nums[id[right]] < target) {
                    left ++;
                } else right --;
            }
            assert(false);
            return vector<int>();
        }
};
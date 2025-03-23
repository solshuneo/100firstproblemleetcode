class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            vector<int> idx(nums.size());
            int id = 0;
            for (auto&x : idx) x = id ++;
            sort(idx.begin(), idx.end(), [&](int x, int y) {
                if (nums[x] == 0) {
                    return (1LL << 31) < nums[y];
                }
                if (nums[y] == 0) {
                    return nums[x] < (1LL << 31);
                }
                return x < y;
            });
            vector<int> ans(nums.size());
            id = 0;
            for (auto &x : ans) {
                x = nums[idx[id++]];
            }
            nums = ans;
        }
    };
class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            int n = nums.size();
            map<int,int> mp;
            for (int i = 1; i <= n; ++i) {
                if (mp[nums[i-1]] > 0) {
                    if (i - mp[nums[i-1]] <= k) return true;
                }
                mp[nums[i-1]] = i;
            }
            return false;
        }
    };
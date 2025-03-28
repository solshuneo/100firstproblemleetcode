class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (i == 0 || nums[i] == nums[i-1]) cnt ++;
                cout << cnt << ' ' << nums[i] << endl;;
                if (i == n-1 || nums[i] != nums[i+1]) {
                    if (cnt > n / 2.0) return  nums[i];
                    cnt = 1;
                }
            }        
            return -1;
        }
    };  
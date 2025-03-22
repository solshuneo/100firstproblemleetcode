class Solution {
    public:
        int mySqrt(int x) {
            int left = 0, right = x;
            int ans = 0;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (1LL * mid * mid <= x) {
                    left = mid + 1;
                    ans = mid;
                } else {
                    right = mid - 1;
                }
            }
            return ans;
        }
    };
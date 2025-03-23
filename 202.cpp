class Solution {
    public:
        bool isHappy(int n) {
            for (int i = 0; i < 100; ++i) {
                int res = 0;
                while (n > 0) {
                    res += (n % 10) * (n % 10);
                    n /= 10;
                }
                n = res;
                if (n == 1) return true;
            }
            return false;
        }
    };
class Solution {
    public:
        int divide(int dividend, int divisor) {
            long long res = 1LL * dividend / divisor;
            if (res > (1LL << 31) - 1) {
                return (1LL << 31) - 1;
            }
            if (res < -(1LL << 31)) {
                return -(1LL << 31);
            }
            return res;
        }
    };
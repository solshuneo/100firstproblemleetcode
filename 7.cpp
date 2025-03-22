class Solution {
    public:
        int reverse(int x) {
            if (x == 0) {
                return 0;
            }
            int sign = x / abs(1LL * x);
            long long reversed = 0;
            if (x == -(1LL << 31)) return 0;
            x = abs(x);
            while (x > 0) {
                reversed = reversed * 10 + x % 10;
                x /= 10;
            }
            reversed *= sign;
            if (reversed >= ((1LL << 31) - 1)) return 0;
            if (reversed < -((1LL << 31))) return 0;
            return reversed;
        }
    };
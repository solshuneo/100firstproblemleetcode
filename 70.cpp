class Solution {
    public:
        int f[46];
        Solution() {
            for (int i = 0; i < 46; ++i) f[i] = -1;
        }
        int climbStairs(int n) {
            if (f[n] != -1) return f[n];
            if (n == 1) return 1;
            if (n == 2) return 2;
            
            return (f[n] = climbStairs(n-1) + climbStairs(n-2));
        }
    };
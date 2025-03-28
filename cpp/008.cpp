class Solution {
    public:
        int myAtoi(string s) {
            int noWhite = 0;
            int n = s.size();
            int sign = 1;
            while (s[noWhite] == ' ' && noWhite < n) noWhite ++;
            if (noWhite < n) {
                if (s[noWhite] == '-' || s[noWhite] == '+') {
                    if (s[noWhite] == '-') sign = -1;
                    noWhite ++;
                }
                if (noWhite < n && isdigit(s[noWhite])) {
                    long long x = 0;
                    for (int i = noWhite; i < n && isdigit(s[i]); ++i) {
                        x = x * 10 + (s[i] - 48);
                        if (x > (1LL << 31) - 1) break;
                        if (x < -(1LL << 31)) break;
                    }
                    if (x > (1LL << 31) - 1) x = (1LL << 31) -1;
                    if (x < -(1LL << 31)) x = -(1LL << 31);
                    return sign * x;
                } 
            }
            return 0;
        }
    };
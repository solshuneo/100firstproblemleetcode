class Solution {
    public:
        bool isPalindrome(int x) {
            long long rev_x = 0;
            int mirror = x;
            while (mirror > 0) {
                rev_x = rev_x * 10 + mirror % 10;
                mirror /= 10;
            }
            return x == rev_x;
        }
};
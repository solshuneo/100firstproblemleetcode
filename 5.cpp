class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.size();
            int max_length = 1;
            int start = -1;
            for (int i = 0; i < n; ++i) {
                int left = i, right = i;
                for (;0 <= left && right < n && s[left] == s[right]; --left, ++right) {}
                if (max_length < right - left - 1) {
                    max_length = right - left - 1;
                    start = left;
                }
    
                left = i-1; right = i;
                for (; 0 <= left && right < n && s[left] == s[right]; --left, ++right) {}
                if (max_length < right - left - 1) {
                    max_length = right - left - 1;
                    start = left;
                }        
            }
            return s.substr(start + 1, max_length);
    
        }
    };
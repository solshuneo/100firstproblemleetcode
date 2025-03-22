class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            const int LETTERS = 256;
            int marker[LETTERS];
            for (int i = 0; i < LETTERS; ++i) marker[i] = 0;
            int res = 0;
            int n = s.size();
            for (int left = 0, right = 0; right < n; ++right) {
                while (marker[s[right]] > 0) {
                    --marker[s[left++]];
                }
                marker[s[right]] ++;
                res = max(res, right - left + 1);
            }
            return res;
        }
    };
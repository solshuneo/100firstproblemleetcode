class Solution {
    public:
        int titleToNumber(string columnTitle) {
            string& a = columnTitle;
            int n = a.size();
            // reverse(a.begin(), a.end());
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                int value = a[i] - 65;
                value += 1;
                ans = ans * 26 + value;
            }
            return ans;
        }
    };
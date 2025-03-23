class Solution {
    public:
        string convertToTitle(int columnNumber) {
            string ans = "";
            while (columnNumber > 0) {
                columnNumber -= 1;
                int remain = columnNumber % 26;
                ans += char(remain + 65);
                columnNumber /= 26;
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };
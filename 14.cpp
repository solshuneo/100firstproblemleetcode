class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.empty()) return "";
            string ans = "";
            for (int i = 0; ; ++i) {
                for (auto x : strs) {
                    if (i == x.size() || x[i] != strs[0][i])  return ans;
                }
                ans += strs[0][i];
            }
            return ans;
        }
    };
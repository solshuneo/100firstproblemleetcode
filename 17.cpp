class Solution {
    public:
        void gen(vector<string>& st, map<int, string>& mp, string digits, string cur, int idx = 0) {
            if (idx == digits.size()) {
                st.emplace_back(cur);
                return;
            }
            for (char x : mp[digits[idx] - 48])
                gen(st, mp, digits, cur + x, idx + 1);
        }
        vector<string> letterCombinations(string digits) {
            if (digits.empty()) {
                return vector<string>();
            }
            map<int, string> mp;
            mp[2] = "abc";
            mp[3] = "def";
            mp[4] = "ghi";
            mp[5] = "jkl";
            mp[6] = "mno";
            mp[7] = "pqrs";
            mp[8] = "tuv";
            mp[9] = "wxyz";
    
            vector<string> st;
            gen(st, mp, digits, "");
            return st;
        }
    };
class Solution {
    public:
    
        void gen(vector<string>&ans, int length, int open = 0, int close = 0, int idx = 0, string cur = "") {
            if (open < close) return ;
            if (open > length) return ;
            if (idx == length * 2) {
                ans.emplace_back(cur);
                return ;
            }
            gen(ans, length, open + 1, close, idx + 1, cur + '(');
            gen(ans, length, open, close + 1, idx + 1, cur + ')');
        }
        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            gen(ans, n);
            return ans;
        }
    };
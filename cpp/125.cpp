class Solution {
    public:
        bool isPalindrome(string s) {
            string alter = "";
            int n = s.size();
            for (int i = 0; i < n; ++i) {
                if (isdigit(s[i]) || isalpha(s[i])) {
                    alter += tolower(s[i]);
                }
            }
            string rev = alter;
            cout << rev << endl;
            reverse(rev.begin(), rev.end());
            return rev == alter;
        }
    };
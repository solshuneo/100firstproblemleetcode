class Solution {
    public:
        string countAndSay(int n) {
            if (n == 1) return "1";
            string res = countAndSay(n - 1);
            int m = res.size();
            int cnt = 1;
            string ans = "";
            for (int i = 0; i < m; ++i) {
                if (i < m - 1 && res[i] == res[i+1]) cnt ++;
                else {
                    ans += to_string(cnt);
                    ans += res[i];
                    cnt = 1;
                }
            }
            return ans;
        }
    };
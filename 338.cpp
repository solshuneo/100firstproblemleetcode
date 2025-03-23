class Solution {
    public:
        vector<int> countBits(int n) {
            vector<int> ans;
            for (int i = 0; i <= n; ++i) {
                int cnt = 0;
                for (int j = 0; j < 20; ++j) {
                    if (i & (1<<j)) {
                        cnt += 1;
                    }
                }
                ans.emplace_back(cnt);
            }
            return ans;
        }
    };
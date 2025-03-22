class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<pair<string, int>> newstr;
            int n = strs.size();
            for (int i = 0; i < n; ++i) {
                string mirror = strs[i];
                sort(mirror.begin(), mirror.end());
                newstr.emplace_back(make_pair(mirror, i));
            }
            sort(newstr.begin(), newstr.end());
            vector<vector<string>> ans;
            for (int i = 0; i < n; ++i) {
                // start sub
                vector<int> cur;
                for (int j = i; j < n; ++j) {
                    if (cur.empty() || newstr[j].first == newstr[(*cur.rbegin())].first) {
                        cur.emplace_back(j);
                    }
                }
                if (!cur.empty()) {
                    i = *cur.rbegin();
                }
                vector<string> res;
                for (auto x : cur) {
                    res.emplace_back(strs[newstr[x].second]);
                }
                ans.emplace_back(res);
            }
            return ans;
        }
    };
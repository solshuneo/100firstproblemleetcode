class Solution {
    public:
        bool wordPattern(string pattern, string s) {
            map<char, string> mp;
            map<string, char> rev;
            string token;
            cout << s << endl;
            stringstream ss(s);
            int idx = 0;
            while (ss >> token) {
                if (mp[pattern[idx]].empty()) {
                    if (rev[token]) {
                        return false;
                    }
                    mp[pattern[idx]] = token;
                    rev[token] = pattern[idx];
                } else {
                    if (token != mp[pattern[idx]]) return false;
                }
                idx ++;
            }
            return idx == pattern.size();
        }
    };
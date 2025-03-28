class Solution {
    public:
        int firstUniqChar(string s) {
            map<char, int> mp;
            for (auto x : s) mp[x] ++;
            int idx = 0;
            for (auto x : s) {
                if (mp[x] == 1) return idx;
                idx ++;
            }
            return -1;
        }
    };
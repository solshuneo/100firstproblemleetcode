class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            map<char, int> mp, mp1;
            for (char c: ransomNote) {
                mp[c] ++;
            }
            for (char c : magazine) {
                mp1[c] ++ ;
            }
            for (auto c : mp) {
                if (mp1[c.first] < c.second) return false;
            }
            return true;
        }
    };
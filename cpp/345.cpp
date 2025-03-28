class Solution {
    public:
        string reverseVowels(string s) {
            vector<int> idx;
            int n = s.size();
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                    idx.emplace_back(i);
                }
                if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                    idx.emplace_back(i);
                }
            }
            for (int i = 0, j = 0; j < idx.size() / 2; ++i) {
                if (i == idx[j]) {
                    swap(s[i], s[idx[idx.size() - j - 1]]);
                    ++j;
                }
            }
            return s;
        }
    };
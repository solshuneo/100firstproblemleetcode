class Solution {
    public:
        int romanToInt(string s) {
            map<char, int> mp;
            mp['I'] = 1; 
            mp['V'] = 5;
            mp['X'] = 10;
            mp['L'] = 50;
            mp['C'] = 100;
            mp['D'] = 500;
            mp['M'] = 1000;
    
            int n = s.size();
            int res = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'I') {
                    if (i + 1 < n) {
                        if (s[i+1] == 'V') res += 4, ++i;
                        else if (s[i+1] == 'X') res += 9, ++i;
                        else res += 1;
                    } else {
                        res += 1;
                    }
                } else if (s[i] == 'X') {
                    if (i + 1 < n) {
                        if (s[i+1] == 'L') res += 40, ++i;
                        else if (s[i+1] == 'C') res += 90, ++i;
                        else res += 10;
                    } else {
                        res += 10;
                    }
                } else if (s[i] == 'C') {
                    if (i + 1 < n) {
                        if (s[i+1] == 'D') {
                            i ++;
                            res += 400;
                        } else if (s[i+1] == 'M') {
                            ++i;
                            res += 900;
                        } else res += 100;
                    } else res += 100;
                } else res += mp[s[i]];
            }
            return res;
        }
    };
class Solution {
    public:
        bool isInterleave(const string& s1, const string& s2, const string& s3, int i1 = 0, int i2 = 0, int i3 = 0) {
            int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
            if (n1 + n2 != n3) return false;
            n1 += 1;
            n2 += 1;
            int dp[n1][n2];
            for (int i = 0; i < n1; ++i) {
                for (int j = 0; j < n2; ++j) {
                    dp[i][j] = false;
                }
            }
            for (int i = 0; i < n1; ++i) {
                for (int j = 0; j < n2; ++j) {
                    if (i == 0 && j == 0) {
                        dp[i][j] = true;                  
                    } else if (i == 0) {
                        dp[i][j] = dp[i][j-1] && s2[j-1] == s3[j-1];
                    } else if (j == 0) {
                        dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i-1];
                    } else {
                        dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1]) || (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
                    }
                }
            }
            return dp[n1-1][n2-1];
        }
    };
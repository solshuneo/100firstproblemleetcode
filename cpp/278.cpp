// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    public:
        int firstBadVersion(int n) {
            int left = 1, right = n;
            int ans = -1;
            while (left <= right) {
                int mid = ((-left + right) >> 1) + left;
                cout << left << ' ' << mid << ' ' << right << endl;
                if (isBadVersion(mid)) {
                    ans = mid;
                    right = mid - 1;
                } else left = mid + 1;
            }
            return ans;
        }
    };
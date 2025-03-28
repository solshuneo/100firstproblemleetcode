class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            // log(m) + log(n) not log(n + m)
            int total = nums1.size() + nums2.size();
            if (total & 1) {
                // assume median appear in nums1
                for (int left = 0, right = nums1.size() - 1; left <= right; ) {
                    int mid = (left + right) >> 1;
                    int lessthan = lower_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin();
                    int lesssamethan = upper_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin();
                    if (lessthan + mid <= total / 2 && total / 2 <= lesssamethan + mid) return nums1[mid];
                    if (lesssamethan + mid < total / 2) {
                        left = mid + 1;
                    } else right = mid - 1;
                }
                // assume median appear in nums2
                for (int left = 0, right = nums2.size() - 1; left <= right; ) {
                    int mid = (left + right) >> 1;
                    int lessthan = lower_bound(nums1.begin(), nums1.end(), nums2[mid]) - nums1.begin();
                    int lesssamethan = upper_bound(nums1.begin(), nums1.end(), nums2[mid]) - nums1.begin();
                    if (lessthan + mid <= total / 2 && total / 2 <= lesssamethan + mid) return nums2[mid];
                    if (lesssamethan + mid < total / 2) {
                        left = mid + 1;
                    } else right = mid - 1;
                }
            } else {
                int upper = -1;
                // assume median appear in nums1
                for (int left = 0, right = nums1.size() - 1; left <= right; ) {
                    int mid = (left + right) >> 1;
                    int lessthan = lower_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin();
                    int lesssamethan = upper_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin();
                    if (lessthan + mid <= total / 2 && total / 2 <= lesssamethan + mid) {
                        upper = nums1[mid];
                        break;
                    }
                    if (lesssamethan + mid < total / 2) {
                        left = mid + 1;
                    } else right = mid - 1;
                }
                // assume median appear in nums2
                for (int left = 0, right = nums2.size() - 1; left <= right; ) {
                    int mid = (left + right) >> 1;
                    int lessthan = lower_bound(nums1.begin(), nums1.end(), nums2[mid]) - nums1.begin();
                    int lesssamethan = upper_bound(nums1.begin(), nums1.end(), nums2[mid]) - nums1.begin();
                    if (lessthan + mid <= total / 2 && total / 2 <= lesssamethan + mid) {
                        upper = nums2[mid];
                        break;
                    }
                    if (lesssamethan + mid < total / 2) {
                        left = mid + 1;
                    } else right = mid - 1;
                }
                // assume median is upper
                int lessthanupper = (lower_bound(nums1.begin(), nums1.end(), upper) - nums1.begin()) + (lower_bound(nums2.begin(), nums2.end(), upper) - nums2.begin());
                int lesssamethanupper = (upper_bound(nums1.begin(), nums1.end(), upper) - nums1.begin()) + (upper_bound(nums2.begin(), nums2.end(), upper) - nums2.begin());
                if (lessthanupper < total / 2 && total / 2 <= lesssamethanupper) {
                    return upper;
                }
                int lower = -1;
                total -= 1;
                // assume median appear in nums1
                for (int left = 0, right = nums1.size() - 1; left <= right; ) {
                    int mid = (left + right) >> 1;
                    int lessthan = lower_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin();
                    int lesssamethan = upper_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin();
                    if (lessthan + mid <= total / 2 && total / 2 <= lesssamethan + mid) {
                        lower = nums1[mid];
                        break;
                    }
                    if (lesssamethan + mid < total / 2) {
                        left = mid + 1;
                    } else right = mid - 1;
                }
    
                // assume median appear in nums2
                for (int left = 0, right = nums2.size() - 1; left <= right; ) {
                    int mid = (left + right) >> 1;
                    int lessthan = lower_bound(nums1.begin(), nums1.end(), nums2[mid]) - nums1.begin();
                    int lesssamethan = upper_bound(nums1.begin(), nums1.end(), nums2[mid]) - nums1.begin();
                    if (lessthan + mid <= total / 2 && total / 2 <= lesssamethan + mid) {
                        lower = nums2[mid];
                        break;
                    }
                    if (lesssamethan + mid < total / 2) {
                        left = mid + 1;
                    } else right = mid - 1;
                }
                return (lower + upper) / 2.0;
            }
            return 0;
        }
    private:
       
    };
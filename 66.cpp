class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            reverse(digits.begin(), digits.end());
            int remain = 1;
            for (auto &x : digits) {
                x += remain;
                remain = x / 10;
                x %= 10;
            }
            if (remain == 1) digits.push_back(1);
            reverse(digits.begin(), digits.end());
            return digits;
        }
    };
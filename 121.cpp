class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int best = 0;
            int n = prices.size();
            for (int left = 0, right = 1; right < n; ++right) {
                best = max(best, prices[right] - prices[left]);
                if (prices[left] > prices[right]) {
                    left = right;
                }
            }
            return best;
        }
    };
    
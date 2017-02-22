// author: Ian
// create on: 2017-02-21
// email: stmayue@gmail.com
// description: Best Time to Buy and Sell Stock II

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int total = 0;
        for (size_t i = 0; i < prices.size() - 1; ++i) {
            if (prices[i] < prices[i + 1]) {
                total += (prices[i + 1] - prices[i]);
            }
        }
        return total;
    }
};
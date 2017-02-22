// author: Ian
// create on: 2017-02-21
// email: stmayue@gmail.com
// description: Best Time to Buy and Sell Stock III

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }

        int vec_size = prices.size();
        int local[vec_size][3] = {0};
        int global[vec_size][3] = {0};

        for (int i = 1; i < prices.size(); ++i) {
            int profit = prices[i] - prices[i - 1];
            for (int j = 1; j <= 2; ++j) {
                local[i][j] = max(local[i - 1][j] + profit, global[i - 1][j - 1] + max(profit, 0));
                global[i][j] = max(local[i][j], global[i - 1][j]);
            }
        }

        return global[vec_size - 1][2];
    }
};
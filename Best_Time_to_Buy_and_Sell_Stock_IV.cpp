// author: Ian
// create on: 2017-03-21
// email: stmayue@gmail.com
// description: Best Time to Buy and Sell Stock IV

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        } else if (k >= prices.size() / 2) {
            int res = 0;
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] - prices[i - 1] > 0) {
                    res += (prices[i] - prices[i - 1]);
                }
            }
            return res;
        }

        int vec_size = prices.size();
        int *local = new int[k + 1];
        int *global = new int[k + 1];
        for (int i = 0; i <= k; ++i) {
            local[i] = 0;
            global[i] = 0;
        }

        for (int i = 1; i < vec_size; ++i) {
            int pre = global[0];
            for (int j = 1; j <= k; ++j) {
                int profit = prices[i] - prices[i - 1];
                local[j] = max(local[j] + profit, pre + max(0, profit));
                pre = global[j];
                global[j] = max(local[j], global[j]);
            }
        }
        return global[k];
    }
};
class Solution {
public:
    int profit = 0;
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        for (int i = 0; i < l; i++) {
            int tmp_buy = prices[i];
            if ( tmp_buy < 0 )
                continue;
            prices[i] = -1;
            for (int j = 0; j < l; j++) {
                if ( i < j && prices[j] > 0) {
                    int tmp_sell = prices[j];
                    prices[i] = -1;
                    profit = max(profit, tmp_sell - tmp_buy);
                    maxProfit(prices);
                    prices[i] = tmp_sell;
                }
            }
            prices[i] = tmp_buy;
        }
        return profit;
    }
};
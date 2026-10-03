class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int profit = 0;
        for (int i = 0; i < prices.size() ; i++)
        {
                profit = max (profit , prices[i] - minprice);
                minprice = min (minprice , prices[i]);
        }
        return profit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==0) return 0;
        vector<int> sell(n,0), buy(n,0);
        int minPrice = prices[0], maxPrice = prices[n-1];
        for (int i=1; i<n; i++) {
            minPrice = min(minPrice, prices[i]);
            sell[i] = max(sell[i-1], prices[i] - minPrice);
        }
        for (int i=n-2; i>=0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            buy[i] = max(buy[i+1], maxPrice-prices[i]);
        }
        int res = buy[0];
        for (int i=1; i<n; i++)
            res = max(res, sell[i-1] + buy[i]);
        return res;
    }
};

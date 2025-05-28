class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0]; // track lowest price to buy so far
        int maxProfit = 0; // max profit found so far

        // start from day 1, try selling on each day
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                // found new lower buy price, update minPrice
                minPrice = prices[i];
            } else {
                // calculate profit if sold today, update maxProfit if better
                int profit = prices[i] - minPrice;
                if (profit > maxProfit) {
                    maxProfit = profit;
                }
            }
        }

        // return max profit, or 0 if no profit possible
        return maxProfit;
    }
};

/* Basically, keep track of the cheapest price to buy so far,
then check if selling today gives a better profit than before.
This way we find the max profit in just one pass.
*/
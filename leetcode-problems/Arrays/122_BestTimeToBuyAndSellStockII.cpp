class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0; // max profit found so far

        // start from day 0, try selling on each day
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                maxProfit += prices[i] - prices[i-1];    

            } 
        }

        // return max profit, or 0 if no profit possible
        return maxProfit;
    }
};

/* Easy logic, if price is higher tomorrow, then buy today and sell tomorrow, keep adding that profit to maxProfit. Repeat this till the last day. */
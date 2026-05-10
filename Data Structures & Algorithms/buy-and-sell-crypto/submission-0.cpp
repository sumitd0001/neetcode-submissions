class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0, r = 1;
        int min = prices[l];
        int profit = 0;
        while (r < n) {
            if (prices[r] < min) {
                min = prices[r];
            }
            else {
                if (profit < (prices[r] - min)) profit = (prices[r] - min);
            }
            r++;
        }
        return profit;
    }
};

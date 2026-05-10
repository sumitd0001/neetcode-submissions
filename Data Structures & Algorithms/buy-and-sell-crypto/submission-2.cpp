class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int buyprice = prices[0];
        for (int i = 1; i<n; ++i) {
            if (buyprice > prices[i]) buyprice = prices[i];
            else if (profit <  prices[i] - buyprice) profit = prices[i] - buyprice;
        }
        return profit;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    









    
    /*
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
    */
};

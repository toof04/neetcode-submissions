class Solution {
public:
//current - minimum so far
    int maxProfit(vector<int>& prices) {
        int lowestday = prices[0];
        int maxP = 0;
        for(int i = 0; i < prices.size(); i++){
            maxP = max(prices[i] - lowestday,maxP);
            lowestday = min(prices[i], lowestday);
        }
        return maxP;
    }
};

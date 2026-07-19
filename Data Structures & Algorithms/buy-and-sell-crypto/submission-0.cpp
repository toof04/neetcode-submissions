class Solution {
public:
//current - minimum so far
    int maxProfit(vector<int>& prices) {
        if(!prices.size())return 0;
        int ithminimum = prices[0];
        int ans = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] - ithminimum > ans)ans = prices[i] - ithminimum;
            if(ithminimum > prices[i])ithminimum = prices[i];
        }
        return ans;
    }
};

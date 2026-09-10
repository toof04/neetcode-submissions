class Solution {
public:
vector<vector<int>>dp;
    int recurse(vector<int>&prices, int i, bool holding){
        if(i>=prices.size())return 0;
        if(dp[i][holding]!=-1)return dp[i][holding];
        if(holding){
            int sell  = prices[i] + recurse(prices, i+2, false);
            int hold = recurse(prices,i+1, true);
            return dp[i][holding] = max(sell,hold);
        }
        else{
            int buy = -prices[i] + recurse(prices, i+1, true);
            int skip = recurse(prices,i+1, false);
            return dp[i][holding] = max(buy,skip);
        }
    
    }



    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size()+1, vector<int>(2,-1));
        return recurse(prices,0,false);
    }
};

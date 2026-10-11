class Solution {
public:

vector<vector<int>>dp;

    int helper(int i, vector<int>&coins, int amount){
        if(amount == 0)return 0;
        if(i >= coins.size() or amount<0)return INT_MAX;
        if(dp[i][amount] != -2)return dp[i][amount];

        //take
        int take = INT_MAX;
            int check =helper(i, coins, amount - coins[i]); 
            if(check!=INT_MAX){
                take = 1 + check;}
        //skip
        int skip = helper(i+1, coins, amount);
        return dp[i][amount] = min(take,skip);
    }



    int coinChange(vector<int>& coins, int amount) {
        int ans = 0;
        dp.resize(coins.size()+1, vector<int>(amount+1,-2));
        int result = helper(0, coins,amount);
        return result == INT_MAX ? -1 :result;
    }
};

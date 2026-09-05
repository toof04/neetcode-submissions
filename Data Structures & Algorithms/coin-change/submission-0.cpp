class Solution {
public:
    vector<int>memo;

    int func(vector<int>&coins, int amount){
        if(amount==0)return 0;
        if(amount<0)return -1;

        if(memo[amount] != -2)return memo[amount];
        int minCoins = INT_MAX;
        for(int coin : coins){
            int result = func(coins, amount - coin);
            if(result != -1)minCoins = min(minCoins, result+1);
        }
        return memo[amount] = (minCoins == INT_MAX ? -1 : minCoins);
    }

    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount+1,-2);
        memo[0] = 0;
        return func(coins, amount);
    }
};

class Solution {
public:

vector<vector<int>>dp;


    int solve(vector<int>& coins, int remaining, int i){
        if(remaining == 0){
            return 1;
        }
                if(i == coins.size())return 0;

        if(dp[i][remaining]!=-1)return dp[i][remaining];
        int take = 0;
        if(remaining - coins[i] >= 0){
             take = solve(coins, remaining - coins[i], i);
        }
        int skip = solve(coins, remaining,i+1);
        return dp[i][remaining] = take + skip;

    }


    int change(int amount, vector<int>& coins) {
        dp.assign(coins.size()+1, vector<int>(amount+1, -1));
        return solve(coins, amount, 0);
    }
};

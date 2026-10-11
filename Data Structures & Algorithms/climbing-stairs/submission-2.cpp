class Solution {
public:
vector<int>dp;

    int helper(int n, int i){
        if(i==n)return 1;
        if(i>n)return 0;
        if(dp[i]!=-1)return dp[i];
        
        return dp[i] = helper(n, i+1) + helper(n, i+2);
    }

    int climbStairs(int n) {
        int i = 0;
        dp.resize(n+1,-1);
        return helper(n,i);
    }
};

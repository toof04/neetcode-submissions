class Solution {
public:
vector<int>dp;
    int helper(int n){
        if(dp[n]!=-1)return dp[n];
        int maxprod = 0;
        for(int i = 1; i<=n;i++){
            int withoutbreaking = i*(n-i);
            int withbreaking = i*helper(n-i);
            maxprod = max({maxprod, withoutbreaking, withbreaking});
        }
        return dp[n] = maxprod;
    }

    int integerBreak(int n) {
        dp.assign(n+1,-1);
        return helper(n);
    }
};
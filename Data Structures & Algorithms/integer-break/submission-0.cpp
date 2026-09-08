class Solution {
public:
vector<int>dp;
    int recur(int n){
        if(dp[n]!=-1)return dp[n];
        int maxprod = 0;
        for(int i = 1; i < n; i++){
            int withoutbreaking = i * (n-i);
            int withbreaking = i * recur(n-i);
            maxprod = max(maxprod, max(withoutbreaking, withbreaking));
        }
        return dp[n]=maxprod;
    }



    int integerBreak(int n) {
        dp.assign(n+1,-1);
        return recur(n);
    }
};
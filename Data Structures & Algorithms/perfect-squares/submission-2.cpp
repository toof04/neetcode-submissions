class Solution {
public:
vector<int>dp;

    int recur(int n){
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        int count = INT_MAX;
        for(int i = 1; i*i <= n; i++){
            count = min(count,1 + recur(n-i*i));
        }
        return dp[n] = count;
    }


    int numSquares(int n) {
        dp.assign(n+1,-1);
        return recur(n);
    }
};
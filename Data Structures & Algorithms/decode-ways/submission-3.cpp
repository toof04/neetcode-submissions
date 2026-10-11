class Solution {
public:
int n = 0;
vector<int>dp;
    int helper(string &s, int i){
        if(i==n)return 1;
        if(dp[i]!=-1)return dp[i];
        if(s[i]=='0')return 0;

        int res = helper(s,i+1);
        if(i+1 < n){
            if(s[i]=='1' or (s[i]=='2' and s[i+1]<'7'))res+=helper(s,i+2);
        }
        return dp[i] = res;
    }


    int numDecodings(string s) {
        n = s.length();
        dp.resize(n+1,-1);
        return helper(s,0);
    }
};

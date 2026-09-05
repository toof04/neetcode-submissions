class Solution {
public:
    vector<vector<int>>dp;
    bool palindrome(const string &s, int i, int j){
        if(i>=j)return true;
        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]!=s[j])return dp[i][j]=false;
        return dp[i][j] = palindrome(s,i+1,j-1);    
        
    }

    int countSubstrings(string s) {
        int n  = s.length();
        int ans = 0;
        dp.assign(n,vector<int>(n,-1));

        for(int i= 0;i<n;i++){
            for(int j = i; j<n;j++ ){
                if(palindrome(s,i,j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};

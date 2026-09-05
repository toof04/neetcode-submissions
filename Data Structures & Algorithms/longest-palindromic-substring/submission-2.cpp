class Solution {
public:
vector<vector<int>>dp;
    bool ispalindrome(const string &s, int i, int j){
        if(dp[i][j]!=-1)return dp[i][j];
        if(i>=j)return true;

        if(s[i]!=s[j])return dp[i][j]=false;
        return dp[i][j] = ispalindrome(s,i+1,j-1);
    }



    string longestPalindrome(string s) {
        int start=0;
        int maxlength = 0;
        int n = s.length();
        dp.assign(n, vector<int>(n, -1));
        
        for(int i = 0; i < n;i++){
            for(int j = i;j<n;j++){
                
                if(ispalindrome(s,i,j)){
                    int length = j-i+1;
                    if(length > maxlength){
                        maxlength = length;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,maxlength);
    }
};

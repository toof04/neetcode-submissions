class Solution {
public:
vector<vector<int>>dp;
    int recurse(string &text1, string &text2, int i , int j){
        
        if (i==text1.size() or j == text2.size())return dp[i][j]=0;
    if(dp[i][j]!=-1)return dp[i][j];
        if(text1[i] == text2[j]){
            return dp[i][j]=1 + recurse(text1, text2, i+1, j+1);
        }

        return dp[i][j]=max(recurse(text1,text2,i+1,j),recurse(text1,text2,i,j+1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(text1.size()+1,vector<int>(text2.size()+1,-1));
        return recurse(text1,text2, 0, 0);
    }
};

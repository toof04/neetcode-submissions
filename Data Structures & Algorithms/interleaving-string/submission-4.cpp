class Solution {
public:
vector<vector<int>>dp;
    bool solve(string s1, string s2, string s3, int i , int j, int k){
        //base
        if(k==s3.length() and i == s1.length() and j == s2.length())return true;
        if(i == s1.length() and s3.substr(k,s3.length()-k)!=s2.substr(j,s2.length()-j))return false;
        if(j == s2.length() and s3.substr(k,s3.length()-k)!=s1.substr(i,s1.length()-i))return false;
        if(dp[i][j]!=-1)return dp[i][j];
        //move i
        bool s1move = false;
        bool s2move = false;
        if(s1[i] == s3[k]){
            s1move = solve(s1,s2,s3,i+1,j,k+1);
        }//move j
        if(s2[j] == s3[k]){
            s2move = solve(s1,s2,s3,i,j+1,k+1);
        }
        if(s1[i]!=s3[k] and s2[j]!=s3[k])return false;

        //return or
        return dp[i][j]=s1move or s2move;
    }



    bool isInterleave(string s1, string s2, string s3) {
        dp.assign(s1.size()+1, vector<int>(s2.size()+1,-1));
        return solve(s1,s2,s3, 0, 0,0);
    }
};

class Solution {
public:
vector<vector<int>>dp;

    bool recur(string s1, string s2, string s3, int i , int j, int k){
        if(k == s3.length() and i == s1.length() and j == s2.length())return true;
        if(i == s1.length() and s2.substr(j, s2.length() - j)!=s3.substr(k, s3.length() - k))return false;
      if(j == s2.length() and s1.substr(i, s1.length() - i)!=s3.substr(k, s3.length() - k))return false;  
        if(dp[i][j]!=-1)return dp[i][j];
        bool moves1 = false, moves2 = false;
        if(s1[i] == s3[k]){
            moves1 = recur(s1, s2, s3, i+1, j , k+1);
        }
        if(s2[j] == s3[k]){
            moves2 = recur(s1,s2,s3, i, j+1, k+1);
        }
        if(s1[i]!=s3[k] and s2[j]!=s3[k])return false;
        return dp[i][j] = moves1 or moves2;
    }


    bool isInterleave(string s1, string s2, string s3) {
        dp.assign(s1.size()+1, vector<int>(s2.size()+1,-1));
        return recur(s1,s2,s3,0,0,0);
    }
};

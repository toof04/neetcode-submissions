class Solution {
public:
vector<vector<int>>dp;
int h;
int w;
    int recurse(int i , int j){
        if(i == h and j == w)return dp[i][j] = 1;
        if(i>h or i<0 or j>w or j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j] = recurse(i+1,j) + recurse(i,j+1);
    }



    int uniquePaths(int m, int n) {
        dp.assign(m,vector<int>(n,-1));
        h = m-1;
        w = n-1;
        return recurse(0,0);
    }
};

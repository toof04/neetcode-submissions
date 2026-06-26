class Solution {
public:
  int dfs(vector<vector<int>>&dp, vector<vector<int>>grid, int i, int j){
    int n = grid.size();
    int m = grid[0].size();
    if(i>=n or j>=m)return INT_MAX;
    
    
    if(i==n-1 and j == m-1){
        return grid[i][j];
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int right = dfs(dp,grid,i+1,j);
    int down = dfs(dp,grid,i,j+1);
    return dp[i][j]=grid[i][j] + min(right,down);
    
  }
    int minPathSum(vector<vector<int>>& grid) {
            int n = grid.size();
    int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
      return dfs(dp,grid,0,0);
    }
};
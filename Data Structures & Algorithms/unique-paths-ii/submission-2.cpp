class Solution {
public:
vector<vector<int>>dp;
int h = 0;
int w = 0;

    int recur(vector<vector<int>>& obstacleGrid, int i , int j){
        if(i>h or j>w){
            return 0;
        }

        if(i == h and j == w)return dp[i][j] = 1;
        if(obstacleGrid[i][j] == 1)return dp[i][j]=0;
        if(dp[i][j]!=-1)return dp[i][j];

        return dp[i][j]=recur(obstacleGrid,i+1,j) + recur(obstacleGrid,i,j+1);
    }



    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        h = obstacleGrid.size() -1;
        w = obstacleGrid[0].size() -1;
        if(obstacleGrid[h][w]==1)return 0;
        dp.assign(h+1,vector<int>(w+1,-1));
        return recur(obstacleGrid,0,0);
    }
};
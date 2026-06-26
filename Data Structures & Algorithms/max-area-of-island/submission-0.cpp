class Solution {
public:

    void dfs(int &islands,vector<vector<int>>& grid,vector<vector<int>>&visited, int i, int j){
        if(grid[i][j]==0 or  visited[i][j]==1)return;
        visited[i][j]=1;
        islands++;
        int n = grid.size();
        int m = grid[0].size();
        if(i+1<n)dfs(islands,grid,visited,i+1,j);
        if(i-1>=0)dfs(islands,grid,visited,i-1,j);
        if(j+1<m)dfs(islands,grid,visited,i,j+1);
        if(j-1>=0)dfs(islands,grid,visited,i,j-1);
    }




    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //union find
        //dfs first
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int maxarea = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j]==0)continue;
                if(!visited[i][j]){
                    int islands = 0;
                    dfs(islands,grid,visited,i,j);
                    maxarea=max(maxarea,islands);
                }
            }
        }
        return maxarea;
    }
};

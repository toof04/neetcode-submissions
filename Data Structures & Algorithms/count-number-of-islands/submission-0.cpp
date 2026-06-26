class Solution {
public:

    void dfs(vector<vector<char>>& grid,vector<vector<int>>&visited, int i, int j){
        if(grid[i][j]=='0' or  visited[i][j]==1)return;
        visited[i][j]=1;
        
        int n = grid.size();
        int m = grid[0].size();
        if(i+1<n)dfs(grid,visited,i+1,j);
        if(i-1>=0)dfs(grid,visited,i-1,j);
        if(j+1<m)dfs(grid,visited,i,j+1);
        if(j-1>=0)dfs(grid,visited,i,j-1);
    }




    int numIslands(vector<vector<char>>& grid) {
        //union find
        //dfs first
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int islands = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j]=='0')continue;
                if(!visited[i][j]){
                    islands++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return islands;
    }
};

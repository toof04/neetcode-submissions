class Solution {
public:
    void dfs(vector<vector<int>>&visited, vector<vector<char>>& grid,int i, int j, bool c ){
         if(grid[i][j]=='X')return;
         
         if(visited[i][j])return;

        if(c==false){
            grid[i][j]='X';
        }


        if(!visited[i][j])visited[i][j]=1;

        int n = grid.size();
        int m = grid[0].size();
        if(i+1<n)dfs(visited,grid,i+1,j,c);
        if(j+1<m)dfs(visited,grid,i,j+1,c);
        if(i-1>=0)dfs(visited,grid,i-1,j,c);
        if(j-1>=0)dfs(visited,grid,i,j-1,c);
    }

    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        // c means border
        bool c = true;
        for(int j = 0;j<m;j++){
            if(grid[0][j] == 'O' and !visited[0][j]){
                dfs(visited,grid,0,j,c);
            }
        }

        for(int j = 0;j<m;j++){
            if(grid[n-1][j] == 'O' and !visited[n-1][j]){
                dfs(visited,grid,n-1,j,c);
            }
        }

        for(int i = 0;i<n;i++){
            if(grid[i][0] == 'O' and !visited[i][0]){
                dfs(visited,grid,i,0,c);
            }
        }

        for(int i = 0;i<n;i++){
            if(grid[i][m-1] == 'O' and !visited[i][m-1]){
                dfs(visited,grid,i,m-1,c);
            }
        }
        c = false;
        for(int i = 0; i<n;i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j]=='O' and !visited[i][j]){
                    dfs(visited,grid,i,j,c);
                }
            }
        }




    }
};

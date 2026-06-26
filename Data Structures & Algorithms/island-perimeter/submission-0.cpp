class Solution {
public:
    int count(vector<vector<int>>& grid, int i , int j){
        int c = 0;
        int n = grid.size();
        int m = grid[0].size();
        if(i+1<n and grid[i+1][j]==0)c++;
        if(i-1>=0 and grid[i-1][j]==0)c++;
        if(j+1<m and grid[i][j+1]==0)c++;
        if(j-1>=0 and grid[i][j-1]==0)c++;

        if(i==0)c++;
        if (i==n-1) c++;
        if (j==m-1)c++;
        if(j==0  )c++;

        cout<<c<<"-";
        return c;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for(int i = 0; i<n;i++){
            for(int j = 0; j<grid[0].size();j++){
                if(grid[i][j]==1)ans+=count(grid,i,j);
            }
            
        }
        return ans;
    }
};
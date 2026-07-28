class Solution {
public:

    void trav(vector<vector<int>>&grid, vector<vector<int>>&visited, int h, int w, int i, int j , int dist){
        if(i >= h or j>=w or i<0 or j<0)return ;
        
        if(grid[i][j] == -1)return ;

        if(visited[i][j] <= dist)return;       


        visited[i][j] = dist;
        if(grid[i][j] != 0){
        grid[i][j] = min(grid[i][j], dist);
        }
        trav(grid,visited,h,w,i+1,j,dist+1);
        trav(grid,visited,h,w,i-1,j,dist+1);
        trav(grid,visited,h,w,i,j+1,dist+1);
        trav(grid,visited,h,w,i,j-1,dist+1);

    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        //if(!grid.size() or !grid[0].size())return {{}};
        int h = grid.size();
        int w = grid[0].size();
        for(int i = 0 ; i < h ; i++){
            for(int j = 0; j < w; j++){
                 if(grid[i][j]==0){
                  vector<vector<int>> visited(h, vector<int>(w, INT_MAX));
                trav(grid,visited,h,w, i, j, 0);}
            }
        }
        
    }
};

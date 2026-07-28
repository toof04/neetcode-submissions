class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid[0].size();
        queue<pair<int,int>>trav;
        for(int i = 0 ; i < h ; i++){
            for(int j = 0; j < w; j++){
                 if(grid[i][j]==0){
                trav.push({i,j});}
            }
        }

        int dir[4][2]={
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };
        while(!trav.empty()){
             auto [i,j] = trav.front();
            trav.pop();
        for(int k = 0 ; k < 4; k++){
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];

            if(ni < 0 || nj < 0 || ni >= h || nj >= w)
                    continue;

            if(grid[ni][nj] != INT_MAX)continue;

            grid[ni][nj] = grid[i][j] + 1;

            trav.push({ni,nj});
        }
        }

    }
};

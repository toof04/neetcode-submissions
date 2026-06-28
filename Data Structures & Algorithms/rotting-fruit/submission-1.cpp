class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        for(int i = 0; i<grid.size();i++){
            for(int j = 0; j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if (grid[i][j]==1)fresh++;

            }   
        }


        int ans = 0;
        while(!q.empty()){
            bool pushed = false;
            int l = q.size();
            for(int k = 0; k < l;k++){
            int i  = q.front().first;
            int j = q.front().second;
            q.pop();
            
            if(i+1<n and grid[i+1][j]==1){q.push({i+1,j});pushed=true;fresh--;grid[i+1][j]=0;}
            if(j+1<m and grid[i][j+1]==1){q.push({i,j+1});pushed=true;fresh--;grid[i][j+1]=0;}
            if(i-1>=0 and grid[i-1][j]==1){q.push({i-1,j});pushed=true;fresh--;grid[i-1][j]=0;}
            if(j-1>=0 and grid[i][j-1]==1){q.push({i,j-1});pushed=true;fresh--;grid[i][j-1]=0;}
 
           } if(pushed)ans++;
            
        }
        if(fresh!=0)return -1;
        return ans;

    }
};

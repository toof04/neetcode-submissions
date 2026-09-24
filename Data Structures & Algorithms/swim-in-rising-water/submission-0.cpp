class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>>pq;

        vector<vector<int>>dist(n, vector<int>(n,INT_MAX));

        dist[0][0] = grid[0][0];

        pq.push({grid[0][0],0,0});


        int dr[] = {-1, 1 , 0 , 0};
        int dc[] = {0 , 0 , -1 , 1}; 
        while(!pq.empty()){
            auto [level, r , c] = pq.top();
            pq.pop();
            if(dist[r][c] < level)continue;

            if(r == n-1 and c == n-1) return level;

            for(int i= 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr<0 or nc<0 or nr>=n or nc>=n)continue;

                int curr = grid[nr][nc];
                int newlevel = max(curr, level);

                if(newlevel<dist[nr][nc]){
                    dist[nr][nc] = newlevel;
                    pq.push({newlevel, nr, nc});
                }

            }
        }
        return 0;
    }
};

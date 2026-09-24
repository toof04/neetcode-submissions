class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>>dist(m, vector<int>(n, INT_MAX));
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>,greater<T>> pq;

        dist[0][0] = 0;
        pq.push({0,0,0});

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!pq.empty()){
            auto [effort, r , c] = pq.top();
            pq.pop();

            if(dist[r][c] < effort)continue;
             if(r == m-1 and c == n-1)return effort;

            for(int i = 0 ; i < 4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr < 0 or nc<0 or nr >= m  or nc >= n)continue;
                int diff = abs(heights[nr][nc] - heights[r][c]);
                int neweffort = max(effort, diff);

                if(neweffort < dist[nr][nc]){
                    dist[nr][nc] = neweffort;
                    pq.push({neweffort, nr, nc});

                }
            }
        }
        return 0;
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //tuple contains <mineffort, i , j>
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>pq;
        int result = INT_MAX;

        vector<vector<int>>dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        dist[0][0] = 0;
        pq.push({0,0,0});
        int dr[] = {0,0,-1,1};
        int dc[] = {1,-1,0,0};
        while(!pq.empty()){
            auto [effort,r,c] = pq.top();
            pq.pop();
            if(r == heights.size()-1 and c == heights[0].size()-1)return effort;
            if(dist[r][c] < effort)continue;

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr<0 or nc<0 or nr>=heights.size() or nc >= heights[0].size())continue;
                int diff = abs(heights[nr][nc] - heights[r][c]);
                int neweffort = max(diff,effort);
                if(neweffort < dist[nr][nc]){
                    dist[nr][nc] = neweffort;
                    pq.push({neweffort,nr,nc});
                }
            }
        }
        return -1;
    }
};
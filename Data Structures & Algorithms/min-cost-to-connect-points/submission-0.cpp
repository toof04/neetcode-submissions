class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //creating the distance matrix of i and j
        int n = points.size();
        vector<vector<int>>dist(n, vector<int>(n,0));
        for(int i = 0 ; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int cost = abs(points[i][0] - points[j][0] )+abs(points[i][1]-points[j][1]);
                dist[i][j] = cost;
                dist[j][i] = cost;
            }
        }
        vector<bool>visited(n,false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        int totalcost = 0;
        int visit = 0;
        pq.push({0,0});
        while(!pq.empty() and visit<n){
            auto [cost, node] = pq.top();
            pq.pop();

            if(visited[node])continue;

            visited[node] = true;
            visit++;

            totalcost+=cost;

            for(int i = 0; i < n; i++){
                if(!visited[i]){
                    pq.push({dist[node][i], i});
                }
            }
        }
        return totalcost;

    }
};

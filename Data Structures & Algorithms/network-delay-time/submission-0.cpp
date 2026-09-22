class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //the maximum distance of djikstas from source to node will be the answer
        //adj matrix
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i :times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int>dist(n+1,INT_MAX);

        dist[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,k});

        while(!pq.empty()){
            auto [currshortestdist, node] = pq.top();
            pq.pop();
            //pruning
            if(currshortestdist > dist[node])continue;

            for(auto [neighbor, weight] : adj[node]){
                if(currshortestdist + weight < dist[neighbor]){
                    dist[neighbor]=currshortestdist+ weight;
                    pq.push({dist[neighbor],neighbor});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i < dist.size(); i++){
            if(dist[i]==INT_MAX)return -1;
            ans = max(ans,dist[i]);
        }
        return ans;


    }
};

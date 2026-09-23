class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,INT_MAX);

        dist[src]=0;

        for(int i = 0; i < k + 1 ; i++){
            vector<int>temp = dist;
            for(auto edge : flights){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if(dist[u]!=INT_MAX and dist[u]+wt < temp[v]){
                    temp[v] = dist[u]+wt;
                }
            }
            dist = temp;
        }

        if(dist[dst]==INT_MAX )return -1;

        return dist[dst];



    }
};

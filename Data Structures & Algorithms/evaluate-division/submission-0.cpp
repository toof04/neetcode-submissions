class Solution {
public:

    double bfs(string src, string target, unordered_map<string, vector<pair<string, double>>>adj){
        if(!adj.count(src) or !adj.count(target)){
            return -1.0;
        }
        queue<pair<string, double>>q;
        unordered_set<string>visited;

        q.push({src,1.0});
        visited.insert(src);

        while(!q.empty()){
            auto [node, weight] = q.front();
            q.pop();

            if(node == target)return weight;

            for( auto [neighbor, neighborsweight] : adj[node]){
                if(!visited.count(neighbor)){
                    visited.insert(neighbor);
                    q.push({neighbor, weight * neighborsweight});
                }
            }
        }
        return -1.0;

    }



    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //here ab does not mean a*b, ab is a variable on its own
        //a/b = 2 , means a -> b with edge 2, and b -> a with edge 1/2.
        //so create an adjacent matrix, and traverse the queries

        // x/y means is there a path from x to y?  and if yes, then keep multiplying the edges for the answer
     
        int n = equations.size();
           unordered_map<string, vector<pair<string, double>>> adj(n);
        for(int i = 0; i < n; i++){
            string a = equations[i][0];
            string b =equations[i][1];
            double value = values[i];

            adj[a].push_back({b,value});
            adj[b].push_back({a, 1/value});
        }

        vector<double> res;
        for(auto query: queries){
            string src = query[0];
            string target = query[1];
            res.push_back(bfs(src,target,adj));
        }
        return res;
    }
};
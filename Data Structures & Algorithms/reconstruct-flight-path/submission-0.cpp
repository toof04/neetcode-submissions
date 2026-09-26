class Solution {
public:
vector<string>ans;
unordered_map<string,vector<string>>adj;

    void dfs(string curr){
        while(!adj[curr].empty()){
            string neighbor = adj[curr].back();
            adj[curr].pop_back();

            dfs(neighbor);
        }
        ans.push_back(curr);
    }



    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto i : tickets){
            adj[i[0]].push_back(i[1]);
        }
        unordered_map<string,bool>visited;

        for(auto &[from, to ] : adj){
            sort(to.rbegin(), to.rend());
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};

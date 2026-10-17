class Solution {
public:
    void dfs(int i, vector<vector<int>>pairs,vector<int>&visited){
        
        visited[i] = 1;

        for(int next : pairs[i]){
            if(!visited[next]){
            dfs(next,pairs,visited);
        }}

        
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0);
        vector<vector<int>>pairs(n);
        for(vector<int> edge : edges){
            pairs[edge[0]].push_back(edge[1]);
            pairs[edge[1]].push_back(edge[0]);
        }
        int count = 0;    
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i, pairs,visited);
            }
        }
        return count;   
    }
};

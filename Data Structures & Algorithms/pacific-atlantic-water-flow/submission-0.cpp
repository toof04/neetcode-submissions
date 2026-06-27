class Solution {
public:

    void atl_dfs(bool &reached, vector<vector<int>>&atlantic, vector<vector<int>>&visited, vector<vector<int>>&heights, int i , int j ){
        if(visited[i][j])return;
        if(!visited[i][j])visited[i][j]=1;
        if(i==heights.size()-1 or j==heights[0].size()-1)reached = true;
        //bottom and right only
        if(i-1>=0 and heights[i-1][j]<=heights[i][j])atl_dfs(reached, atlantic,visited,heights,i-1,j);
        if(j-1>=0 and heights[i][j-1]<=heights[i][j])atl_dfs(reached, atlantic,visited,heights,i,j-1);
        if(i+1<heights.size() and heights[i+1][j]<=heights[i][j])atl_dfs(reached,atlantic,visited,heights,i+1,j);
        if(j+1<heights[0].size() and heights[i][j+1]<=heights[i][j])atl_dfs(reached,atlantic,visited,heights,i,j+1);

        
    }
    


    void pac_dfs(bool &reached,vector<vector<int>>&pacific, vector<vector<int>>&visited, vector<vector<int>>&heights, int i , int j ){
        if(visited[i][j])return;
        if(!visited[i][j])visited[i][j]=1;
        if(i==0 or j==0)reached = true;
        //top and left only
        if(i-1>=0 and heights[i-1][j]<=heights[i][j])pac_dfs(reached,pacific,visited,heights,i-1,j);
        if(j-1>=0 and heights[i][j-1]<=heights[i][j])pac_dfs(reached,pacific,visited,heights,i,j-1);
        if(i+1<heights.size() and heights[i+1][j]<=heights[i][j])pac_dfs(reached,pacific,visited,heights,i+1,j);
        if(j+1<heights[0].size() and heights[i][j+1]<=heights[i][j])pac_dfs(reached,pacific,visited,heights,i,j+1);

        
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>pacific;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>atlantic;
         vector<vector<int>>ans;
        for(int i = 0; i<n;i++){
            for(int j = 0; j<m;j++){
                vector<vector<int>>visited(n,vector<int>(m,0));
                 vector<vector<int>>visited1(n,vector<int>(m,0));
                bool a = false;
                pac_dfs(a,pacific,visited,heights,i,j);
                bool b = false;
                atl_dfs(b, atlantic,visited1,heights,i,j);
                if (a and b)ans.push_back({i,j});
            }
        }
        cout<<pacific.size()<<" "<<atlantic.size();

        return ans;
    }
};

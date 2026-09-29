class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //the tree formed will be the same regardless, it will contain the same edges. only visually it seems like a different tree where the top node is visually at the top.

        //keep removing layers of edge - leaf nodes. i.e. nodes with indegree == 1

        
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        if(n==1)return {0};
        for(int i = 0 ; i< n-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }

        queue<int>q;
        for(int i = 0; i < n; i++){
            if(indegree[i]==1)q.push(i);
        }

        int remaining = n;
        
        //the answer will contain atmost 2 nodes
        while(remaining>2){
            int size = q.size();
            remaining-=size;
            //doing this way because wont whole layer to get removed, then process next layer. to do it layer by layer
            while (size--) {
            int node = q.front();
            q.pop();
            for(int neighbor : adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor]==1)q.push(neighbor);
            }}   
        }
        vector<int>answer;
        while(!q.empty()){
            answer.push_back(q.front());
            q.pop();
        }


        return answer;
    }
};
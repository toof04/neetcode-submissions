class Solution {
public:

    vector<int>toposort(int k, vector<vector<int>>&conditions){
        //adjacency matrix from conditions
        vector<vector<int>>adj(k+1);
        vector<int>indegree(k+1,0);
        for(auto cond : conditions){
            adj[cond[0]].push_back(cond[1]);
            indegree[cond[1]]++;
        }
        queue<int>q;
        for(int i = 1; i <=k; i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>order;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);
            for(int neighbor : adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0)q.push(neighbor);
            }
        }

        if(order.size()!=k)return {};
        return order;
    }





    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    //toposort for rowconditions
    //toposort for colconditions
    //place in matrix
        vector<int>rowOrder = toposort(k, rowConditions);      
        vector<int>colOrder = toposort(k, colConditions);

        if(rowOrder.empty() or colOrder.empty())return {};

        //placing it into the answer matrix

        //map number to row index. if row is 2 0 1, we make 2->0 0->1 1->2
        vector<int>rowPos(k+1);
        vector<int>colPos(k+1);
        for(int i = 0; i < k ; i++){
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }

        vector<vector<int>>ans(k,vector<int>(k,0));

        for(int num = 1; num <=k; num++){
            ans[rowPos[num]][colPos[num]] = num;
        }
        return ans;



    }
};
class Solution {
public:

    int find(vector<int>&roots, int x){
        if (roots[x]==x){
            return x;
        }
        return roots[x]=find(roots,roots[x]);


    }
    bool unite(vector<int>&roots, int x, int y){
        if (x!=y){
            roots[x]=y;
            return true;
        }
        return false;

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>roots(n+1);
        for(int i = 0; i<n; i++){
            roots[i]=i;
        }
        vector<int>ans(2,0);
        for(auto edg : edges){
            int x = find(roots,edg[0]);
            int y = find(roots,edg[1]);
            if (!unite(roots,x,y)){
                ans[0]=edg[0];
                ans[1]=edg[1];
            }
        }

        return ans;
    }
};

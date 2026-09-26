class Solution {
public:
    class DSU{
    public:
    vector<int>parent;
        DSU(int n){
            parent.resize(n);
            for(int i = 0 ; i < n ; i++){
                parent[i] = i;
            }
        }

        int find(int node){
            if(parent[node]==node)return node;
            return parent[node] = find(parent[node]);
        }

        bool unite(int u, int v){
            int rootu = find(u);
            int rootv = find(v);
            if(rootu==rootv)return false;
            parent[rootu]=rootv;
            return true;
        }
    };



    bool canTraverseAllPairs(vector<int>& nums) {
        int size = 0;
        int n = nums.size();
        DSU dsu(n);
        for(int i = 0; i < n; i++){
            for(int j = 1; j<n; j++){
                if(i!=j){
                    if(gcd(nums[i],nums[j])>1){
                        if(dsu.unite(i,j))size++;
                    }
                }
            }
        }
        return size == n-1;
    }
};
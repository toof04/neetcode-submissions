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

vector<int>calcprimfactors(int num){
    vector<int>ans;
    for(int i = 2; i*i <=num; i++){
        if(num%i==0){ans.push_back(i);
        while(num%i==0){
            num/=i;
        }
        }
    }
    if(num>1)ans.push_back(num);
    return ans;
}

    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return true;
        //if nums contains 1 then it cant have gcd > 1 with anything
        for(int x : nums)if(x==1)return false;
        
        DSU dsu(n);

        unordered_map<int,int>firstprimeat;

        for(int i = 0; i < n; i++){
            vector<int>factors = calcprimfactors(nums[i]);

            for(int p : factors){
                if(firstprimeat.count(p)){
                    if(dsu.unite(i, firstprimeat[p]));
                }
                else firstprimeat[p] = i;
            }
        }
        for(int i = 1; i < n;i++){
            if(dsu.find(i)!=dsu.find(0))return false;
        }
        return true;
    }
};
class Solution {
public:

class DSU{
public:
int size = 0;
vector<int>parent;    
    DSU(int n){
        size = n;
        parent.resize(n);
        for(int i = 0; i < n;i++){
            parent[i] = i;
        }
    }

    int find(int node){
        if(parent[node]==node)return node;
        return parent[node] = find(parent[node]);
    }

    bool unite(int a, int b){
        int parenta = find(a);
        int parentb = find(b);
        if(parenta==parentb)return false;
        parent[parenta] = parentb; 
        return true;
    }

};



    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>answer;
         DSU dsu(edges.size() + 1);
        for(vector<int> edge : edges ){
            if(!dsu.unite(edge[0],edge[1])){
                return{edge[0],edge[1]};
            }
        }
        return answer;
    }
};

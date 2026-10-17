class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)return false;
        int arr[100];
        sort(edges.begin(), edges.end());
        for(vector<int>edg : edges){
            arr[edg[0]]++;
            arr[edg[1]]++;
            if(arr[edg[0]]>1 and arr[edg[1]]>1)return false;
        }
        return true;
    }
};

class Solution {
public:

    void traverse(int start,int n, int k, vector<vector<int>>&ans, vector<int>&temp,vector<bool>used){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int i = start; i <= n; i++){
            if(used[i])continue;
            used[i]=true;
            temp.push_back(i);
            traverse(i+1,n,k,ans,temp,used);
            temp.pop_back();
            used[i]=false;
        }
    }




    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>used;
        used.resize(n+1,false);
        traverse(1,n,k,ans,temp,used);
        return ans;
    }
};
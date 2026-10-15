class Solution {
public:

    void recurse(int n, int k, int i, vector<int>temp, vector<vector<int>>&ans){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }


        for(int start = i; start <= n; start++){
            temp.push_back(start);
            recurse(n,k,start+1, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>ans;
        recurse(n,k,1,temp,ans);
        return ans;
    }
};
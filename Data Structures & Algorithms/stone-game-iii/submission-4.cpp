class Solution {
public:
vector<vector<int>>dp;
int n;

    int dfs(int i, vector<int>& stoneValue, int alice){
        if(i >= n)return 0;
        if(dp[i][alice]!=INT_MIN)return dp[i][alice];

        int res;
        if(alice)res=INT_MIN;
        else res = INT_MAX;

        int score = 0;
        for(int j = i; j < min(i+3, n); j++){
            score += stoneValue[j];
            if(alice){
                res = max(res, score + dfs(j+1, stoneValue, 0));
            }
            else{
                res = min(res, -score + dfs(j+1, stoneValue, 1));
            }
        }
        return dp[i][alice] = res;
    }



    string stoneGameIII(vector<int>& stoneValue) {
          n = stoneValue.size();
          int sum = 0;
          dp.resize(n, vector<int>(2,INT_MIN));
          int res = dfs(0, stoneValue, 1);
          if(res == 0)return "Tie";
          if(res>0)return "Alice";
          else return "Bob";
    }
};
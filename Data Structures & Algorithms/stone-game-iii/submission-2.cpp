class Solution {
public:
vector<int>dp;
int n;

    int dfs(int i, vector<int>& stoneValue){
        if(i >= n)return 0;
        if(dp[i]!=INT_MIN)return dp[i];

        int res;
        res=INT_MIN;
 
        int score = 0;
        for(int j = i; j < min(i+3, n); j++){
                score+=stoneValue[j];
                res = max(res, score - dfs(j+1, stoneValue));
        }
        return dp[i] = res;
    }



    string stoneGameIII(vector<int>& stoneValue) {
          n = stoneValue.size();
          int sum = 0;
          dp.resize(n, INT_MIN);
          int res = dfs(0, stoneValue);
          if(res == 0)return "Tie";
          if(res>0)return "Alice";
          else return "Bob";
    }
};
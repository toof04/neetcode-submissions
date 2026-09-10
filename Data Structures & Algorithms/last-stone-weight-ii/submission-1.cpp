class Solution {
public:
int total = 0;
vector<vector<int>>dp;
    int recur(vector<int>&stones, int runningsum, int i){
        if (runningsum > total)return 0;
        if(i == stones.size())return runningsum;
        if(dp[i][runningsum]!=-1)return dp[i][runningsum];
        int take = recur(stones, runningsum + stones[i], i + 1);
        int skip = recur(stones, runningsum, i + 1);
        return dp[i][runningsum]=max(take,skip);
    }


    int lastStoneWeightII(vector<int>& stones) {
    int fulltotal = accumulate(stones.begin(), stones.end(), 0);
    total = fulltotal/2;
    dp.assign(stones.size()+1,vector<int>(total+1,-1));
    int maxleftpart = recur(stones, 0 , 0);
    return fulltotal - 2*maxleftpart;
    }
};
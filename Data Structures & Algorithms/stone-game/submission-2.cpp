class Solution {
public:
vector<vector<int>>dp;
    int solve(vector<int>&piles, int left, int right){
        if(left>right)return 0;

        if(dp[left][right]!=-1)return dp[left][right];


        int takeLeft = piles[left] - solve(piles, left+1, right);
        int takeRight = piles[right] - solve(piles, left, right -1);

        return dp[left][right] = max(takeLeft, takeRight);
    }




    bool stoneGame(vector<int>& piles) {
        dp.assign(piles.size()+1, vector<int>(piles.size()+1, -1));
        return solve(piles, 0 , piles.size()-1) > 0;
    }
};
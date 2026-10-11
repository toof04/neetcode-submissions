class Solution {
public:

int n = 0;
vector<int>dp;
    int helper(vector<int>&nums, int i){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int skip = helper(nums, i+1);
        int take = nums[i] + helper(nums, i+2);
        return dp[i] = max(skip, take);
    }


    int rob(vector<int>& nums) {
        int i = 0;
        n = nums.size();
        dp.resize(n+1,-1);
        return helper(nums, i);
    }
};

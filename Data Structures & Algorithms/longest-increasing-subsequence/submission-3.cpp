class Solution {
public:
vector<vector<int>>dp;
    int recurse(vector<int>&nums, int i, int j){
        if(i == nums.size())return 0;
        if(dp[i][j+1] != -1)return dp[i][j+1];
        //skip
        int LIS = recurse(nums, i+1, j);
        //take
        if(j==-1 or nums[i]>nums[j]){
            LIS = max(LIS, 1 + recurse(nums, i+1, i));
        }
        return dp[i][j+1] = LIS;
    }


    int lengthOfLIS(vector<int>& nums) {
        dp.assign(nums.size()+1, vector<int>(nums.size()+1, -1));
        return recurse(nums,0, -1);
    }
};

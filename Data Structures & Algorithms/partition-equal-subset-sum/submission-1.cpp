class Solution {
public:


    int tot = 0;
    vector<vector<int>>dp;
    bool recur(int i, vector<int>&nums, int sum){
        if(sum==tot)return true;
        if (sum> tot)return false;
        if(i == nums.size())return false;

        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }

        bool leave = recur(i+1, nums, sum);

        bool take = recur(i+1, nums, sum+nums[i]);
        return dp[i][sum] = leave or take;
    }

    bool canPartition(vector<int>& nums) {
        tot = accumulate(nums.begin(), nums.end(),0);
        if(tot%2==1)return false;
        tot=tot/2;
        dp.assign(nums.size(), vector<int>(tot+1,-1));
        return recur(0,nums, 0);
        
    }
};

class Solution {
public:
vector<int>dp;
    int recur(vector<int>&nums, int target){
        if(0 == target){return 1;}
        if(dp[target]!=-1)return dp[target];
        int count = 0;

        for(int i = 0 ; i < nums.size(); i++){
           if ( nums[i] <=  target) count+= recur(nums, target - nums[i]);
        }

        return dp[target] = count;
    
    }


    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1,-1);
        return  recur(nums, target);
    }
};
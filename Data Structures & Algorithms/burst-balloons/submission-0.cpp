class Solution {
public:

vector<vector<int>>dp;
    int recurse(vector<int>&nums, int l , int r){
        if(l+1==r)return 0;

        if(dp[l][r]!=-1)return dp[l][r];

        int answer = 0;
        for(int k = l+1; k<r; k++){
            int left = recurse(nums,l,k);
            int right = recurse(nums,k,r);
            int burst = nums[l]*nums[k]*nums[r];
            int candidate = left + right + burst;
            answer = max(answer,candidate);
        }

        return dp[l][r] = answer;
    }


    int maxCoins(vector<int>& nums) {
        dp.assign(nums.size()+2, vector<int>(nums.size()+2, -1));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return recurse(nums,0,nums.size()-1);
    }
};

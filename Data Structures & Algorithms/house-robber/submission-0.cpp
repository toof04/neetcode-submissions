class Solution {
public:
vector<int>memo;
    int traverse(vector<int>&nums, int i){
        if(i > nums.size()-1)return 0;

        if(memo[i] != -1)return memo[i];    
        
        return memo[i] = max(traverse(nums,i+1), nums[i] + traverse(nums,i+2)); 
    }


    int rob(vector<int>& nums) {
    memo.resize(nums.size(),-1);
    return traverse(nums, 0);   
    }
};

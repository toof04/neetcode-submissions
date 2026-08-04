class Solution {
public:
vector<int>memo;
    int traverse(vector<int>&nums, int i, int end){
        if(i >= end)return 0;

        if(memo[i] != -1)return memo[i];    
        int take = nums[i] + traverse(nums,i+2,end);
        int skip = traverse(nums,i+1,end);
        return memo[i] = max(take,skip); 
    }


    int rob(vector<int>& nums) {
    if(nums.size()==1)return nums[0];        
    memo.resize(nums.size(),-1);
    int a  = traverse(nums, 0, nums.size()-1);
    memo.assign(nums.size(),-1);
    int b = traverse(nums,1,nums.size());
    return max(a,b );   
    }
};

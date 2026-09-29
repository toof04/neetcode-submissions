class Solution {
public:
    
    void backtrack(int i , int currxor, int &total, vector<int>&nums){
        if( i == nums.size()){
            total+=currxor;
            return;
        }
        backtrack(i+1,currxor^nums[i],total, nums);
        backtrack(i+1,currxor,total, nums);
    }

    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        backtrack(0,0, ans, nums);
        return ans;
    }
};
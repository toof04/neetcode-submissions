class Solution {
public:

    void traverse(vector<int>&nums, int target, vector<int>&temp, vector<vector<int>>&ans, int i , int currsum){
        if(currsum>target){
            return;
        }
        if(currsum == target){
            ans.push_back(temp);
            return;
        }
         if(i>=nums.size() )return;

        
        temp.push_back(nums[i]);
        traverse(nums,target,temp,ans,i+1,currsum+nums[i]);
        temp.pop_back();
        int j = i;
        while(j<nums.size()-1 and nums[j]==nums[j+1])j++;
        traverse(nums,target,temp,ans,j+1,currsum);


        
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        
        traverse(nums,target,temp,ans,0,0);

        return ans;
    }
};

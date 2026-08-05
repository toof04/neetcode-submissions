class Solution {
public:

    void traverse(vector<int>nums, int &target, vector<int>temp, vector<vector<int>>&ans, int i , int currsum){
        if(i>nums.size()-1)return;
        if(currsum>target){
            return;
        }
        if(currsum == target){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        traverse(nums,target,temp,ans,i,currsum+nums[i]);
        temp.pop_back();
        traverse(nums,target,temp,ans,i+1,currsum);


        
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        
        traverse(nums,target,temp,ans,0,0);
        return ans;
    }
};

class Solution {
public:

    void traverse(vector<vector<int>>&ans, vector<int>&temp, vector<bool>used, vector<int>& nums){
        
        if(temp.size()==nums.size()){
            ans.push_back(temp);
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i])continue;
            used[i] = true;
            temp.push_back(nums[i]);
            traverse(ans,temp,used,nums);
            temp.pop_back();
            used[i] = false;
        while(i+1<nums.size() and nums[i]==nums[i+1])i++;
        }
    }



    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>used(nums.size()+1,false);
        traverse(ans,temp,used,nums);
        return ans;
    }
};
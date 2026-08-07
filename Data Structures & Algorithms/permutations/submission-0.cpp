class Solution {
public:

  void  traverse(vector<vector<int>>&ans, vector<int>&temp, vector<int>&nums, vector<bool>used){
        
        if(temp.size() == nums.size()){
            ans.push_back(temp);
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i]){
                continue;
            }
            used[i] = true;

            temp.push_back(nums[i]);
            traverse(ans,temp,nums,used);
            temp.pop_back();
            used[i] = false;
           // traverse(ans,temp,nums,used);


        }
    
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>used(nums.size()+1, false);
        traverse(ans,temp,nums, used);
        return ans;
    }
};

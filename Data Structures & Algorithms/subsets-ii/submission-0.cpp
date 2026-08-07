class Solution {
public:
    void traverse(vector<vector<int>>&ans, vector<int>&temp, vector<bool>used, vector<int>&nums, int i){
        if(i >= nums.size()){
            ans.push_back(temp);
            return;
        }
        if(used[i])return;

        used[i] = true;
        temp.push_back(nums[i]);
        traverse(ans,temp,used,nums,i+1);
        temp.pop_back();
          while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
        traverse(ans,temp,used,nums,i+1);

    } 


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(), nums.end()); 
      vector<vector<int>>ans;
      vector<int>temp;
      vector<bool>used(nums.size()+1,false);  
       traverse(ans,temp,used,nums,0);
        return ans;      

    }
};

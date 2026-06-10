class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>>ans;
        for(int i = 0 ; i<nums.size(); i++){
            int target = nums[i];
            int l = i+1;
            int r = nums.size()-1;         
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            while(l<r){
                int currsum = nums[l]+nums[r] + target;

                if(currsum<0){
                    l++;
                }
                else if(currsum>0)r--;
                else{
                    
                    ans.push_back({target, nums[l], nums[r] });
   // Skip duplicate pairs
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                }
            }

        }

        return ans;
    }
};

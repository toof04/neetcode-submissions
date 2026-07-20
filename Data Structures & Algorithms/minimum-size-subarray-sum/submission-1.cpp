class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int currwindow = 0;
        int answindow = INT_MAX;
        
        int total = 0;

        int i = 0;
        for(int j = 0; j < nums.size(); j++){
             total+=nums[j];
            while(total>=target){
               
                answindow=min(answindow,j-i+1);
                total-=nums[i];
                 i++;

            }

        }
        return answindow==INT_MAX?0:answindow;
    }
};
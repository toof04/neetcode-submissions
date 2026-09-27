class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int &i : nums){
            if(i<0)i=0;
        }
        for(int i =0; i < nums.size(); i++){
            int val = abs(nums[i]);
            if(1<= val and val<= nums.size()){
                //negate the value present at index val-1 (0 based indexing)
                if(nums[val-1]>0)nums[val-1]=-1*nums[val-1];

                //if the value at that index is 0, then to mark it as visited we set it to a number outside the range and negate it
                if(nums[val-1]==0)nums[val-1]=-1*(nums.size()+1);
            }
        }

        for(int i = 1; i <=nums.size();i++){
            //hence not visited
            if(nums[i-1]>=0){
                return i;
            }
        }

        return nums.size()+1;

    }
};
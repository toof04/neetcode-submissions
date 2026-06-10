class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int currentcontender = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[currentcontender]==nums[i]){
                count++;
            } 
            else count--;

            if(count<=0){currentcontender=i;count++;}
        }
        return nums[currentcontender];
    }
};
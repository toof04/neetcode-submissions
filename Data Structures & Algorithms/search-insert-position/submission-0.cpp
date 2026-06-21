class Solution {
public:
    int bs(vector<int>& nums, int target, int left, int right){
        if(left>right)return left;
        int mid = left + (right - left)/2;
        if(target==nums[mid])return mid;
        else if (target>nums[mid]) return bs(nums,target,mid+1,right);
        else return bs(nums,target,left,mid-1);
    }
    int searchInsert(vector<int>& nums, int target) {
        return bs(nums, target, 0, (int)nums.size()-1);
    }
};
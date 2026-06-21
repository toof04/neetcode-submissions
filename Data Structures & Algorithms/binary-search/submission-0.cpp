class Solution {
public:
    int bs (vector<int>& nums, int left,int right,int target){
        if (left>right)return -1;
        int mid = left + (right - left)/2;
        if(nums[mid] == target)return mid;
        else if (nums[mid] < target) return bs(nums,mid+1,right,target);
        else return bs(nums,left, mid-1,target);
    }
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        return bs(nums,0,n-1,target);
    }
};

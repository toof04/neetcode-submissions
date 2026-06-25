class Solution {
public:
    int binary(vector<int>&nums,int left, int right, int target){
        if(left>right)return -1;
        int mid = left + (right-left)/2;
        if(nums[mid]==target)return mid;
        else if(nums[mid]>target)return binary(nums,left,mid-1,target);
        else  return binary(nums,mid+1,right,target);
       
    }
    int search(vector<int>& nums, int target) {
        //find the pivot point first
        int n = (int)nums.size();
        int l = 0;
        int r = n-1;
        if (n==1){
            if(nums[0]==target)return 0;
            else return -1;
        }
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]) l = mid+1;
            else if(nums[mid] < nums[r]) r = mid;
            else r--;              // duplicate: can't decide, shrink

        }
        int pivot = l;
        
        
        int leftpart = binary(nums,0,pivot,target);
        int rightpart = binary(nums,pivot,n-1,target);

        if(leftpart != -1 )return leftpart;
        if(rightpart != -1 )return rightpart;

        return -1;        

    }
};

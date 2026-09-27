class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;

        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target)return true;

            if(nums[l] < nums[mid]){
                if(nums[l]<=target and nums[mid]>target)r=mid-1;
                else l = mid+1;
            }
            else if(nums[l] > nums[mid]){
                if(nums[mid] < target and target <= nums[r])l=mid+1;
                else r = mid-1;
            }
            else l++;    
        
        }







        return false;
    }
};
class Solution {
public:
    bool cansplit(int mid,  vector<int>&nums, int k){
        int subarray = 1, currsum = 0;
        for(int num : nums){
            currsum+=num;
            if(currsum > mid){
                // = num because we are taking the current element into addition
                currsum = num;
                subarray++;
            }
        }

        //less than equal to k because that means we can search for a smaller sum in our main binary search
        return subarray <= k;
    }
    
    
    int splitArray(vector<int>& nums, int k) {
        //smallest subarray sum can be max element
        //largest subarray sum can be the sum of all elements

        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);

        //now do binary search on this answer
        int res = r;
        while(l<=r){
            int mid = l + (r - l)/2;
            if(cansplit(mid, nums, k)){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return res;
    }


};
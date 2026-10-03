class Solution {
public:


    int cansplit(vector<int>&nums, int sum){
        int splits = 1;
        int curr = 0;
        for(int i = 0; i<nums.size(); i++){
            curr+=nums[i];
            if(curr>sum){
                splits++;
                curr = nums[i];
            }
        }
        return splits;
    }



    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        
        while(l<=r){
            int mid = l+(r-l)/2;

            if(cansplit(nums,mid) <= k) r = mid-1;
            else l = mid+1;
        }

        return l;
         

    }
};
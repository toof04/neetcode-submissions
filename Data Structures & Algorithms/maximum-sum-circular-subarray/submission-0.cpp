class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        int sum = nums[0];

        int mn= nums[0];
        int minsum = nums[0];

        int total = nums[0];

        for (int i = 1; i < n; i++) {
            total+=nums[i];
        
            sum = max(nums[i], sum+nums[i]);
            mx = max(mx, sum);

            minsum = min(nums[i], minsum+nums[i]);
            mn = min(mn, minsum);
        }

        if (mx<0)return mx;



        return max(mx,total-mn);
    }
};
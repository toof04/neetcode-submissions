class Solution {
public:

    vector<vector<int>> dp;

    int solve(vector<int>& nums, int i, int remaining) {

        // We processed all elements
        if (i == nums.size()) {
            return remaining == 0;
        }

        // Since nums contains non-negative numbers,
        // we cannot recover from a negative remaining sum
        if (remaining < 0) {
            return 0;
        }

        if (dp[i][remaining] != -1) {
            return dp[i][remaining];
        }

        // Don't take nums[i]
        int notTake = solve(nums, i + 1, remaining);

        // Take nums[i]
        int take = solve(nums, i + 1,
                         remaining - nums[i]);

        return dp[i][remaining] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int total = accumulate(nums.begin(), nums.end(), 0);

        // Target is outside possible range
        if (abs(target) > total)
            return 0;

        // Required subset sum must be an integer
        if ((total + target) % 2 != 0)
            return 0;

        int required = (total + target) / 2;

        dp.assign(nums.size(),
                  vector<int>(required + 1, -1));

        return solve(nums, 0, required);
    }
};
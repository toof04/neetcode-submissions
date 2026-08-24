class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        for(int i = 0; i<nums.size();i++){
            s.insert(nums[i]);
        }
        int longest = 0;
        int curr = 0;
        int prev = INT_MIN;
        for(auto i : s){
            if(i==prev+1){
                curr++;
            }
            else curr = 1;

            longest = max(longest, curr);

            prev = i;
        }
        return longest;
    }
};

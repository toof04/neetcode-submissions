class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(int i = 0; i<nums.size();i++){
            s.insert(nums[i]);
        }
        int longest = 0;
        for(auto i : s){
            if(s.find(i-1)==s.end()){
                int curr = i;
                int currsize = 1;
                while(s.find(curr+1)!=s.end()){
                    curr++;
                    currsize++;
                }
                longest = max(longest, currsize);
            }
        }
        return longest;
    }
};

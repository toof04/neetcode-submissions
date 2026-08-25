class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int currsum = 0;
        int res = 0;
        map<int,int>oldsum;
        oldsum[0]=1;

        for(int num : nums){
            currsum+=num;
            int diff = currsum - k;
            res+=oldsum[diff];
            oldsum[currsum]++;
        }
        return res;
    }
};
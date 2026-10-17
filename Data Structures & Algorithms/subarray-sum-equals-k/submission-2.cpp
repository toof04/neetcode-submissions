class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int currsum = 0;
        int answer = 0;
        map<int,int>runningsum;
        runningsum[0] = 1;
        for(int n : nums){
            currsum+=n;
            int diff = currsum - k;
            answer+=runningsum[diff];
            runningsum[currsum]++;
        }
        return answer;
    }
};
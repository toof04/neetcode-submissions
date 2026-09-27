class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int>dq;
        int n = nums.size();
        vector<int>ans(n-k+1);
        int l = 0, r = 0;
        while(r < n){
            //new number is greater than numbers in the back, as we are iterating from left to right - these numbers wont be the maximum again
            while(!dq.empty() and nums[dq.back()] < nums[r]){
                dq.pop_back();
            }
            //add element
            dq.push_back(r);

            //remove the front if our window has moved
            if(l > dq.front()){
                dq.pop_front();
            }
            //window has reached its max size, so we output
            if((r+1) >= k){
                ans[l] = nums[dq.front()];
                l++;             
            }       
            r++;
        
        }
        return ans;
    }
};

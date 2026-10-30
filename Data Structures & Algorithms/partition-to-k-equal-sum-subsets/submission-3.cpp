class Solution {
public:

int done = 0;
int requiredsum = 0;
vector<int>visited;
    bool recurse(vector<int>&nums, vector<int>temp, int runningsum, int k, int start){
        if(k==0)return true;
        if(runningsum==requiredsum){
            return recurse(nums, temp, 0 , k-1, 0);
        }
        

        for(int i = start; i < nums.size(); i++){
            if(visited[i] or runningsum + nums[i] > requiredsum)continue;
           if( runningsum + nums[i] <= requiredsum) {
            visited[i] = true;
           if ( recurse(nums,temp,runningsum + nums[i], k, i+1)){
           return true;
           }
           visited[i] = false;
                       }
        }
        
        return false;
    }


    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        visited.assign(nums.size(), false);
        requiredsum = totalsum/k;
          sort(nums.rbegin(), nums.rend());
        if(totalsum%k!=0)return false;
        vector<int>temp;
        return recurse(nums, temp, 0,  k, 0);
    }
};
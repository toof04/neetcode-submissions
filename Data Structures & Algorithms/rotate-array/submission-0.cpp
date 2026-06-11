class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
         k = k%n;

        vector<int>before,after;
        for(int i = 0; i<n;i++){
            if(i<n-k)before.push_back(nums[i]);
            else after.push_back(nums[i]);
        }
        for(int j = 0;j<after.size();j++){
            nums[j]=after[j];
        }
        for(int l = 0;l<before.size();l++){
            nums[l+after.size()]=before[l];
        }


    
    }
};
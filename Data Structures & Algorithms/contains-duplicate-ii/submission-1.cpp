class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int l) {
        
     
            set<int>windows;
            for(int k = 0; k<nums.size();k++){
                if(windows.find(nums[k])!=windows.end())return true;
                
                windows.insert(nums[k]);

                if(windows.size()>l)windows.erase(nums[k-l]);

            }

        return false;
    }
};
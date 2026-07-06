class Solution {
public:

    bool canJump(vector<int>& nums) {
        int maxreached = 0;
        for(int i = 0; i<nums.size();i++){
            if ( i > maxreached )return false;
            maxreached = max(maxreached, i + nums[i]);
            if(maxreached>=nums.size()-1)return true;
        }

        return true;
    }
};

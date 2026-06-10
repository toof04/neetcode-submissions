class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> m;
        for(int i = 0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        int j = 0;
        for(auto i = m.begin(); i!=m.end(); i++ ){
        nums[j++] = i->first;
        }
        
        
        
        return m.size();

    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        for(int i = 0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        vector<vector<int>>frequency(nums.size() + 1);

        for(auto i =  m.begin();i!=m.end() ;i++){
            frequency[i->second].push_back(i->first);
        }

        vector<int>ans;
        for(int i = frequency.size()-1;i>=0;i--){
        for(int n: frequency[i]){
        ans.push_back(n);
        if(ans.size()==k)return ans;
        
        }}
        return ans;
        
    }
};

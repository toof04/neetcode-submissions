class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0;
        unordered_set<char>sets;
        for(int i = 0; i<s.size(); i++){
            while(sets.find(s[i])!=sets.end()){
                sets.erase(s[left]);
                left++;
            }
             sets.insert(s[i]);
            ans = max(ans, (int)sets.size());

         
        }
        return ans;
    }
};

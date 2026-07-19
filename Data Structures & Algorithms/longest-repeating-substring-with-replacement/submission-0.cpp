class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxwindow = 0;
        int maxFreq = 0;
        vector<int>freqmap(27,0);
        unordered_set<char>sets;
        for(int i = 0; i<s.size(); i++){
            freqmap[s[i]-'A']++;
            maxFreq = max(maxFreq,freqmap[s[i]-'A']);
            int windowlength = i-left+1;
            if(windowlength-maxFreq>k){
                freqmap[s[left]-'A']--;
                left++;
            }
            windowlength = i - left + 1;
            maxwindow = max(maxwindow, windowlength);
         
        }
        return maxwindow; 
    }
};

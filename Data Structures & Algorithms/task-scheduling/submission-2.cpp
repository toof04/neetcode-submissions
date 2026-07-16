class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(27,0);
        int maxFreq = 0;
        for(char i : tasks){
            freq[i-'A']++;
            maxFreq = max(maxFreq,freq[i-'A']);
        }
        int numWithMaxFreq = 0;
        for(int i : freq){
            if(i==maxFreq)numWithMaxFreq++;
        }
        int ans = (maxFreq - 1) * (n + 1) + numWithMaxFreq;
        return max((int)tasks.size(), ans);
    }
};

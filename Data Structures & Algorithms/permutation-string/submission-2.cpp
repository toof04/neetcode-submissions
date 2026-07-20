class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freqS1(26,0);
        vector<int>freqS2(26,0);

        for(char i : s1){
            freqS1[i-'a']++;
        }
        
        int windowsize = s1.length();
        int j=0;
        int currwindow = 0;
        for(int i = 0;i < s2.length(); i++){
           freqS2[s2[i]-'a']++;
           currwindow++;
           if(currwindow > windowsize){
            freqS2[s2[j]-'a']--;
            currwindow--;
            j++;
           }   
           if(currwindow == windowsize and freqS2 == freqS1)return true;        

        }
        return false;
        
    }
};

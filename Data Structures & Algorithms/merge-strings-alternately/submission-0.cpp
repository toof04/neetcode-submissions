class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i, j;
        i = j = 0;
        while(true){
            if(i<word1.length())ans+=word1[i++];
            if(j<word2.length())ans+=word2[j++];
            if(i>=word1.length() and j>=word2.length())break;
        }
        return ans;
    }
};
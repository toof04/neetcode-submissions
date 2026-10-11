class Solution {
public:
vector<int>dp;
    bool recur(string s, vector<string>& wordDict, int i){
        if(i==s.length())return true;
        if(dp[i]!=-1)return dp[i];
        for(string word : wordDict){
            if(i + word.length() <= s.length() and s.substr(i, word.length()) == word){
                if(recur(s, wordDict, i+word.length()))return dp[i] = true;
            }
            
        }
        return dp[i] = false;
    }



    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.length(), -1);
        return recur(s, wordDict, 0);
    }
};

class Solution {
public:

vector<int>dp;

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>words(dictionary.begin(), dictionary.end());
        dp.resize(s.length()+1,-1);
        return dfs(0,s,words);
    }
private:

    //from this i/start what is the min additional character needed
    int dfs(int start , const string&s, unordered_set<string>& words){
        if(start==s.size())return 0;
        if(dp[start]!=-1)return dp[start];
        //this was the additional char
        int ans = 1 + dfs(start+1, s , words);

        for(int end = start; end < s.size(); end++){
            if(words.count(s.substr(start, end - start + 1))){
                ans = min(ans, dfs(end+1, s, words));
            }
        }
        return dp[start] = ans;
    
    }
};
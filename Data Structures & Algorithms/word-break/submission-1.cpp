class Solution {
public:
    vector<int> dp;

    bool recur(int i, string &s, vector<string>& wordDict) {
        if (i == s.length())
            return true;

        if (dp[i] != -1)
            return dp[i];

        for (string word : wordDict) {
            if (i + word.length() <= s.length() &&
                s.substr(i, word.length()) == word) {

                if (recur(i + word.length(), s, wordDict))
                    return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.length() + 1, -1);
        return recur(0, s, wordDict);
    }
};
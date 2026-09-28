class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> words(dictionary.begin(), dictionary.end());

        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            // Don't match s[i]
            dp[i] = dp[i + 1];

            // Try every substring starting at i
            for (int j = i; j < n; j++) {
                string word = s.substr(i, j - i + 1);

                if (words.count(word)) {
                    int len = j - i + 1;

                    // Match this word
                    dp[i] = max(dp[i], len + dp[j + 1]);
                }
            }
        }

        return n - dp[0];
    }
};
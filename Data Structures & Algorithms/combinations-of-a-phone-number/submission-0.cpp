class Solution {
   public:
    unordered_map<char, string> keys;

    void backtrack(string& digits, int i, string& curr, vector<string>& results) {
        if (i == digits.length()) {
            results.push_back(curr);
            return;
        }
        string letters = keys[digits[i]];
        for (char c : letters) {
            curr.push_back(c);
            backtrack(digits, i + 1, curr, results);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        keys['2'] = "abc";
        keys['3'] = "def";
        keys['4'] = "ghi";
        keys['5'] = "jkl";
        keys['6'] = "mno";
        keys['7'] = "pqrs";
        keys['8'] = "tuv";
        keys['9'] = "wxyz";

        vector<string> result;
        string curr = "";
        backtrack(digits, 0, curr, result);
        return result;
    }
};

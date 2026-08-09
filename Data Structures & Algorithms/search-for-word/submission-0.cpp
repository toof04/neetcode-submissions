class Solution {
public:

    bool recurse(vector<vector<char>>& board, string word,
                 string temp, int i, int j, int next) {

        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size())
            return false;

        if (board[i][j] == '#')
            return false;

        if (next >= word.size())
            return false;

        if (board[i][j] != word[next])
            return false;

        temp += board[i][j];

        if (temp == word)
            return true;

        char ch = board[i][j];
        board[i][j] = '#';

        bool ans =
            recurse(board, word, temp, i + 1, j, next + 1) ||
            recurse(board, word, temp, i - 1, j, next + 1) ||
            recurse(board, word, temp, i, j + 1, next + 1) ||
            recurse(board, word, temp, i, j - 1, next + 1);

        board[i][j] = ch;

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == word[0]) {

                    string temp = "";

                    if (recurse(board, word, temp, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
};
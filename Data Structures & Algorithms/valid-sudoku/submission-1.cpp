class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>>rows,cols;
        map<pair<int,int>,unordered_set<int>>squares;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j]=='.')continue;
                pair<int,int>squarekey = {i/3, j/3};
                if(squares[squarekey].count(board[i][j]) or rows[i].count(board[i][j]) or cols[j].count(board[i][j]))return false;

                squares[squarekey].insert(board[i][j]);
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
            }
        }
        return true;
    }
};

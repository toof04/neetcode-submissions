class Solution {
public:
        int n = 0;
        vector<vector<string>>answer;
        vector<bool>samecol; //same column
        //there can be 2*n-1 diagonals to a n*n matrix
        vector<bool>leftdiagonal; //left diagonal 
        vector<bool>rightdiagonal; //right diagonal backslash

    void recurse(int rowinsert, vector<string>& current){
        if(rowinsert == n){
            answer.push_back(current);
            return;
        }

            for(int j = 0; j < n; j++){
                int d1 = rowinsert + j;
                int d2 = rowinsert - j + n - 1;
                
                //another queen already exists on the same column/either of the diagonals
                if(samecol[j] or leftdiagonal[d1] or rightdiagonal[d2])continue;
                
                samecol[j] = true; leftdiagonal[d1] = true; rightdiagonal[d2] = true;
                current[rowinsert][j] = 'Q';

                recurse(rowinsert+1, current);
                
                samecol[j] = false; leftdiagonal[d1] = false; rightdiagonal[d2] = false;
            }
            
    }
    int totalNQueens(int size) {
        n = size;
        vector<string>current(n, string(n,'.'));   
        samecol.resize(n,false);
        leftdiagonal.resize(2*n-1,false);
        rightdiagonal.resize(2*n-1,false);
        recurse(0,current);
        return answer.size();
        
    }
};

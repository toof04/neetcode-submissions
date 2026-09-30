class Solution {
public:
int n = 0;
vector<vector<string>>answer;

    bool validboard(vector<string>&current){
        vector<bool>samecol(n,false); //same column
        //there can be 2*n-1 diagonals to a n*n matrix
        vector<bool>leftdiagonal(2*n-1,false); //left diagonal 
        vector<bool>rightdiagonal(2*n-1,false); //right diagonal backslash


        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (current[i][j] == 'Q'){
                    if(samecol[j])return false;
                    //for values in a specific left diagonal i + j remains constant
                    if(rightdiagonal[i+j])return false;
                    //for values in a specific right diagonal i - j remains constant, we add n+1 for spacing
                    if(leftdiagonal[i-j+n-1])return false;
                    
                    samecol[j] = true;
                    rightdiagonal[i+j] = true;
                    leftdiagonal[i-j+n-1] = true;
                }
            }
        }

        return true;
    }


    void recurse(int rowinsert, vector<string>& current){
            if(rowinsert == n){
                answer.push_back(current);
                return;
            }
                for(int j = 0; j < n; j++){
                    current[rowinsert][j] = 'Q';
                    if(validboard(current))recurse(rowinsert+1, current);
                    current[rowinsert][j] = '.';
                }
            
    }
    vector<vector<string>> solveNQueens(int size) {
        n = size;
        vector<string>current(n, string(n,'.'));   
        recurse(0,current);
        return answer;
        
    }
};

class Solution {
public:
vector<vector<int>>dp;

    bool leftpossible(vector<vector<int>>&matrix, int i , int j){
        if(j-1<0)return false;
        if(matrix[i][j-1]>matrix[i][j])return true;
        return false;
    }
    bool rightpossible(vector<vector<int>>&matrix, int i , int j){
        if(j+1==matrix[0].size())return false;
        if(matrix[i][j+1]>matrix[i][j])return true;
        return false;
    }
    bool downpossible(vector<vector<int>>&matrix, int i , int j){
        if(i+1==matrix.size())return false;
        if(matrix[i+1][j]>matrix[i][j])return true;
        return false;
    }
    bool uppossible(vector<vector<int>>&matrix, int i , int j){
        if(i-1<0)return false;
        if(matrix[i-1][j]>matrix[i][j])return true;
        return false;
    }

    bool nofurther(vector<vector<int>>&matrix, int i , int j){
        if(!leftpossible(matrix,i,j) and !rightpossible(matrix,i,j) and !downpossible(matrix,i,j) and !uppossible(matrix,i,j))return true;
        return false;
    }


    int solve(vector<vector<int>>&matrix, int i , int j){
        //no further increasing from this position
        if(nofurther(matrix,i,j))return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int left = 0;
        if(leftpossible(matrix,i,j)) left =  1 + solve(matrix, i, j-1);

        int right = 0;
        if(rightpossible(matrix,i,j)) right = 1 + solve(matrix, i, j+1);
        
        int down = 0;
        if(downpossible(matrix,i,j)) down =  1 + solve(matrix, i+1, j);
        
        int up = 0;
        if(uppossible(matrix,i,j)) up =  1 + solve(matrix, i-1, j);

        return dp[i][j] = max({left, right, down, up});

    }



    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //state of dp[i][j]= after this i,j whats the max length we can achieve
        dp.assign(matrix.size()+1, vector<int>(matrix[0].size()+1,-1));
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size();j++){
                int calculate = solve(matrix, i ,j);
                ans = max(ans,calculate);
            }
        }
        return ans;
    }
};

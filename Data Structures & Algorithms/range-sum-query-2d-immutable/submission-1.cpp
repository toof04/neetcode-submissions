class NumMatrix {
public:

vector<vector<int>>sum;


    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size() + 1;
        int cols = matrix[0].size() + 1;
        sum.assign(rows,vector<int>(cols,0));
        for(int i = 0; i < rows - 1; i++){
           int prefix = 0;
           for(int j = 0; j < cols - 1;j++){
                int above = sum[i][j+1];
                prefix+=matrix[i][j];
                sum[i+1][j+1] = prefix + above;
           } 
        }   
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;col1++;row2++;col2++;

        int bottomright = sum[row2][col2];
        int left = sum[row2][col1-1];
        int top = sum[row1-1][col2];
        int topleft = sum[row1-1][col1-1];

        return bottomright - left - top + topleft;
        
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
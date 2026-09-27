class NumMatrix {
public:
vector<vector<int>>sum;

    NumMatrix(vector<vector<int>>& matrix) {

        //calculating running sums and storing them in a 2d vector
        int rows = matrix.size(); int cols = matrix[0].size();
        sum.resize(rows+1,vector<int>(cols+1,0));
        for(int r = 0; r < rows; r++ ){
            int prefix = 0;
            for(int c = 0; c < cols; c++){
                prefix +=matrix[r][c];
                //above would have been sum[r-1][c], but as there is padding we do sum[r-1+1][c+1]
                int above = sum[r][c+1];
                sum[r+1][c+1] = prefix + above; 
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++; //adding padding

        int bottomright = sum[row2][col2];
        int above = sum[row1-1][col2];
        int left = sum[row2][col1-1];
        int topleft = sum[row1-1][col1-1];
        return bottomright - above - left + topleft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
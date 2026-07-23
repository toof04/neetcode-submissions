class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
     vector<int>ans;
    if(!matrix.size())return {};
    int n = matrix.size();
    int m = matrix[0].size();
    
     int total = n * m;
     if(total<=1) return matrix[0];
    int current = 0;


    int i = 0;
    int j = 0;
    int istart = 0;
    int jstart = 0;
    
    while(current<total){

        while(j<m and current<total){
            
                ans.push_back(matrix[i][j]);
                current++;
                j++;
            
        }
        j--;
        m--;
        i++;
        while(i<n and current<total){
            
                ans.push_back(matrix[i][j]);
                current++;
            i++;
        }
        i--;
        n--;
        j--;
        while(j>=jstart and current<total){
                ans.push_back(matrix[i][j]);
                current++;
            j--;
        }
        j++;
        jstart++;
        i--;

        while(i>istart and current<total){
                ans.push_back(matrix[i][j]);
                current++;
            i--;
        }
        i++;
        istart++;
       j++;


     }   
     return ans;
    }
};

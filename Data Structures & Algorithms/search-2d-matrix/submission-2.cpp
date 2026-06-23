class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;
        int vertmid;
        int hormid;
        while(top<=bottom){
            vertmid = top + (bottom-top)/2;
            if(matrix[vertmid][0] == target)return true;
            else if (vertmid!=matrix.size()-1 and target>matrix[vertmid][0] and target<matrix[vertmid+1][0])break;
            else if(target>matrix[vertmid][0])top = vertmid+1;
            else bottom = vertmid-1;
        }


        while(left<=right){
            hormid = left + (right-left)/2;
            if(matrix[vertmid][hormid] == target)return true;
            else if (target>matrix[vertmid][hormid])left = hormid+1;
            else right = hormid-1;
        }
        cout<<vertmid<<","<<hormid;
        return false;
    }
};

class Solution {
public:
    int maxArea(vector<int>& heights) {


        int maxi = 0;

        for(int l = 0; l<heights.size(); l++){

            for(int r = heights.size()-1; r>=0; r--){
            int mini = min(heights[l], heights[r]);
            maxi = max(maxi, mini*(r-l));
            }}

        return maxi;
        
    }
};

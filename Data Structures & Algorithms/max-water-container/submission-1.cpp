class Solution {
public:
    int maxArea(vector<int>& heights) {


        int maxi = 0;
        int l = 0;
        int r = heights.size()-1;

        while(l<r){
            int mini = min(heights[l], heights[r]);
            maxi = max(maxi, mini*(r-l));
            
            if(heights[l]<heights[r])l++;
            else r--;
            
            }

        return maxi;
        
    }
};

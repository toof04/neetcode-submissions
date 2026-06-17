class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int maxi = heights[0];       
        for(int i = 0; i<heights.size(); i++){
            int k = i+1;
            int mini = heights[i];
            while(k<heights.size() and heights[i]<=heights[k]){
                k++;
            }
            int j = i-1;
            int mini2 = heights[i];

            while(j>=0 and heights[i]<=heights[j]){
                j--;
            }
            int length = (k-j-1)*heights[i];

            cout<<length<<" - ";
            maxi = max(length,maxi);
        }
        return maxi;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>l;
        stack<int>s;
        for(int i = 0 ; i<heights.size();i++){
            while(!s.empty() and heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(s.empty())l.push_back(-1);
            else l.push_back(s.top());

            s.push(i);
        }
        while(!s.empty())s.pop();

        vector<int>r;

        for(int i = heights.size()-1 ; i>=0;i--){
            while(!s.empty() and heights[s.top()]  >= heights[i]){
                s.pop();
            }
            if(s.empty())r.push_back(heights.size());
            else r.push_back(s.top());
            s.push(i);
        }        
        reverse(r.begin(), r.end());
        int maxi = 0;
        for(int i = 0 ; i < heights.size() ; i++){
            maxi = max(maxi, (r[i] - l[i]-1) * heights[i]);
        }
        return maxi;


    }
};
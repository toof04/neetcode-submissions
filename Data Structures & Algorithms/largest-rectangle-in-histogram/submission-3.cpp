class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>prevSmallest(n,-1);
        stack<int>s;
        for(int i = 0;i<n;i++){

        while(!s.empty() and heights[s.top()] >= heights[i]){
        s.pop();}
    
    if(!s.empty())prevSmallest[i] = s.top();
        s.push(i);
    }
    while(!s.empty())s.pop();

    vector<int>nextSmallest(n,n);

    for(int i = n-1 ; i >= 0; i--){

        while(!s.empty() and heights[s.top()] >= heights[i]){
        s.pop();}
    
    if(!s.empty())nextSmallest[i] = s.top();
        s.push(i);
    }

    int ans = 0;
    for(int i = 0 ; i < n; i++){
                    int width = nextSmallest[i] - prevSmallest[i] - 1;
        ans = max(ans,heights[i]*width);

    }
    return ans;

    }
};

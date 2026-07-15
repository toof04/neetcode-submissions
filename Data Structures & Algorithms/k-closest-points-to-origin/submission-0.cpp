class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,vector<int>>, vector<pair<float,vector<int>>>, greater<>>pq;

        for(vector<int> p : points){
            float dist = sqrt(pow((p[0] - 0),2) + pow((p[1] - 0),2));
            pq.push({dist,p});
        }
        vector<vector<int>>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;


    }
};

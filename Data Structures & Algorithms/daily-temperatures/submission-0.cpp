class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>s;
        vector<int>result(temperatures.size(),0);
        for(int i = 0; i <temperatures.size(); i++){
            while(!s.empty() and s.top().second < temperatures[i]){
                result[s.top().first]=(i - s.top().first);
                s.pop();
            }
            s.push({i,temperatures[i]});
        }
        return result;
    }
};

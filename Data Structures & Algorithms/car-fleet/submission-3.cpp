class Solution {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double>s;
        stack<pair<int,int>>s2;
       vector<float>time;

        vector<pair<int,int>>ps;
        for(int i = 0; i< position.size();i++){
            ps.push_back({position[i],speed[i]});
        }

        sort(ps.begin(),ps.end());

       for(int i = 0;i<position.size();i++){
        time.push_back((double)(target-ps[i].first)/ps[i].second);       
       }
       
       
       for(int i = 0;i<position.size();i++){
        cout<<time[i]<<" ";   
       }
       
        s.push(time[0]);
        for(int t=1; t<time.size();t++){
            
            while(!s.empty() and time[t]>s.top())s.pop();

            
            s.push(time[t]);
            
        }
        set<double>se;
        while(!s.empty()){
            if(s.top()!=0)se.insert(s.top());
            s.pop();
        }
        return se.size();


    }
};

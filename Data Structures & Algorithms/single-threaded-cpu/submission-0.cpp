class Solution {
public:

struct Compare{
    bool operator()(vector<int>a,vector<int>b){
        
        if(a[1]==b[1])return a[2]>b[2];
        return a[1]>b[1];
    }
};
struct CompareAT{
    bool operator()(vector<int>a,vector<int>b){
            return a[0]<b[0];
    }
};

    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i = 0; i<tasks.size(); i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end(),CompareAT());
        priority_queue<vector<int>,vector<vector<int>>,Compare>pq;
        vector<int>ans;
        int i = 0;
        long long time = 0;
        while(i<tasks.size() or !pq.empty()){
            //if PQ is empty then jump to next tasks time
            if(pq.empty() and time<tasks[i][0]){
                time=tasks[i][0];
            }
            //if by completion of task n, there are multiple tasks then push all those tasks into  pq
            while(i<tasks.size() and tasks[i][0]<=time){
                pq.push(tasks[i]);
                i++;
            }
            ans.push_back(pq.top()[2]);
            time+=pq.top()[1];
            pq.pop();

        }

        return ans;
    }
};
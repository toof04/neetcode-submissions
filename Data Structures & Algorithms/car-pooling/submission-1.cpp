class Solution {
public:
    struct Compare{
        bool operator()(vector<int>a, vector<int>b){
            return a[1]<b[1];
        }
    };
    struct Departure{
        bool operator()(vector<int>a, vector<int>b){
            return a[2]>b[2];
        }
    };

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), Compare());
                priority_queue<vector<int>,vector<vector<int>>,Departure>car;

        int currCap =0;
        int i = 0;
        while(i<trips.size()){
             while(!car.empty() and trips[i][1]>=car.top()[2]){currCap-=car.top()[0];car.pop();}  
           
            currCap+=trips[i][0];
            if(currCap>capacity)return false;
             car.push(trips[i]);

            i++;
        }

    
        return true;
    }
}; 
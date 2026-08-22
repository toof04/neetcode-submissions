class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for(int i = 0; i < n;i++){
            gas[i]-=cost[i];
        }
        int total = 0;
        int curr = 0;
        int start = 0;
        for(int i = 0;i<n;i++){
            total += gas[i];
            curr+=gas[i];
            if(curr<0){
                curr=0;
                start=i+1;
            }
        }
        if(total<0)return -1;
        return start;
    }
};

class Solution {
public:
vector<int>memo;
    int traverse(vector<int>&cost, int i, int curr){
        int n = cost.size();
        if( i > n-1) return 0;
                if(memo[i]!=-1)return memo[i];

       // curr += cost[i];
        return memo[i]=cost[i] + min(traverse(cost,i+1,curr), traverse(cost,i+2,curr));

    }

    int minCostClimbingStairs(vector<int>& cost) {
        if(!cost.size())return 0;
        memo.resize((int)cost.size(),-1 );
        return min(traverse(cost,0,0),traverse(cost,1,0));
    }
};

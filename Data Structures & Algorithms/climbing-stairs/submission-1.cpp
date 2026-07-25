class Solution {
public:
    int recur(int i, int n,vector<int>&mem){
        if(i>=n){return i==n;}
        if(mem[i]!=-1)return mem[i];
        return mem[i]=recur(i+1,n,mem) +  recur(i+2,n,mem);
    }
    int climbStairs(int n) {
        vector<int>mem(n,-1);
        return recur(0,n,mem);
    }
};

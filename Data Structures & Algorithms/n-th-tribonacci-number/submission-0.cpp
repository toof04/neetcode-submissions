class Solution {
public:
vector<long long> memo;
    int traverse(int n ){
        if (n == 0) return memo[n]=0;
        if (n==1 or n==2) return memo[n]=1;

        if(memo[n] != -1)return memo[n];

        return memo[n] = traverse(n-1) + traverse(n-2) + traverse(n-3);  
    }

    int tribonacci(int n) {
            memo.resize(n+1,-1);       
            return traverse(n);
    }
};
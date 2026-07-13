class Solution {
public:
    vector<int> countBits(int n) {
        if (!n)return {0};
        vector<int> ans(n+1,0);
        ans[0]=0;
        for(int i = 1; i <=n;i++){
           
           if(!(i%2)){
            ans[i] = ans[i/2];
           }
           else ans[i]=ans[i/2]+1;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <=n;i++){
            int dig = i;
            int temp = 0;
            for(int j = 0;j<32;j++){
                if(dig&1)temp++;
                dig=dig>>1;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

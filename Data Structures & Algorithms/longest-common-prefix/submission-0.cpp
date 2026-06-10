class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
            if(strs.size()<=1)return strs[0];
        int n = INT_MAX;
        int l = 0;
        for(int i = 0;i < strs.size() -1; i ++ ){
            l = min(strs[i].length(), strs[i+1].length());
            int m = 0;
            for(int j = 0; j < l;j++){
                if(strs[i][j]==strs[i+1][j]) m++;
                else break;
            }
            n = min(n,m);
        }
        string ans = "";
        for(int i = 0;i<n;i++){
            ans += strs[0][i];
        }
        return ans;      
    }
};
class Solution {
public:
    vector<int>dp;

    bool helper(int i, string &s, int &minj, int &maxj){
                if(i>s.length()-1)return false;
if(dp[i]!=-1)return dp[i];
        if(i == s.length()-1 and s[i]=='0')return true;
                
        if(s[i]=='1')return false;

    for(int j = minj;j<=maxj; j++){
            if(helper(i + j, s , minj, maxj)){
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

    bool canReach(string s, int minj, int maxj) {
        dp.resize(s.size()+1,-1);
        return helper(0, s, minj,maxj);
    }
};
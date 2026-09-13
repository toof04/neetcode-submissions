class Solution {
public:
vector<vector<int>>dp;
    bool solve(string &s, string &p, int i , int j){
        if(j == p.length())return i==s.length();
        if(dp[i][j]!=-1)return dp[i][j];

        //match
        bool match = false;
        if(i < s.length() and s[i]==p[j])match = solve(s,p,i+1,j+1);
        
        //.
        bool dot = false;
        if(i < s.length() and p[j]=='.'){
            dot = solve(s,p,i+1,j+1);
        }

        //*
        bool star = false;
        //when * we can choose to not take current element
        //so we check for next element if its *
        if(j+1 < p.length() and p[j+1]=='*'){
            //dont take x and *
            bool skip = solve(s,p,i, j + 2);
            bool take = false;
            //take x*
            if(i < s.length() and (s[i]==p[j] or p[j] == '.'))take = solve(s,p,i+1,j);
            star = skip or take;
        }
        return dp[i][j] =  match + dot + star;

    }


    bool isMatch(string s, string p) {
        dp.assign(s.length()+1, vector<int>(p.length()+1, -1));
        return solve(s,p,0,0);
    }
};

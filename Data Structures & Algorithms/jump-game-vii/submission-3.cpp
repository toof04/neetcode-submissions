class Solution {
public:
vector<int>memo;    
    bool help(string &s, int &min,int &max, int i ){
        if(i>s.length()-1)return false;
        if(memo[i]!=-1)return memo[i];
        if( i == s.length() - 1 and s[i]=='0'){
        return true;
        }
        if(s[i] == '1')return false;

        for(int step = min; step <= max; step++){
           if( help(s,min,max,i+step)){
            return memo[i] = true;
           } 
        }
        return memo[i] = false;
    }

    bool canReach(string s, int minJump, int maxJump) {
       memo.resize(s.length(),-1);
       return help(s,minJump,maxJump,0);
    }
};
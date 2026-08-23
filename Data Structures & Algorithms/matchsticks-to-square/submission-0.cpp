class Solution {
public:
vector<bool>taken;
    bool recurse(int i, int sidecurr, int sidesize,int sidesdone, vector<int>&matchsticks){
        if(sidesdone==4)return true;
        if(sidecurr==sidesize){return recurse(0,0,sidesize,sidesdone+1,matchsticks);}
        if(i>=matchsticks.size())return false;        

        if(taken[i] or sidecurr+matchsticks[i]>sidesize)return recurse(i+1,sidecurr,sidesize,sidesdone,matchsticks);
        taken[i] = true;
                if(recurse(i+1,sidecurr+matchsticks[i],sidesize,sidesdone,matchsticks))return true;

        taken[i]=false;
       return  recurse(i+1,sidecurr,sidesize,sidesdone,matchsticks);
    }


    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(total%4!=0)return false;
        int sidesize = total/4;
        taken.resize(matchsticks.size(),false);
        return recurse(0,0,sidesize,0,matchsticks);
    }
};
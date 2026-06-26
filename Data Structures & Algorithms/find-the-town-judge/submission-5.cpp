class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>usedonleft(n+1,-1);
        vector<int>timesappearedonright(n+1,0);

        vector<vector<int>>adj(n+1);
        for(vector<int>con: trust){
            adj[con[0]].push_back(con[1]);
            usedonleft[con[0]]++;
            timesappearedonright[con[1]]++;
        }

        vector<int>anslist;
        for(int i = 1;i<usedonleft.size();i++){
            if(usedonleft[i]==-1){anslist.push_back(i);cout<<i;}
            //cout<<usedonleft[i];
        }
        for(int i : anslist){
            if(timesappearedonright[i]==n-1)return i;
        }
        return -1;

        

    }
};
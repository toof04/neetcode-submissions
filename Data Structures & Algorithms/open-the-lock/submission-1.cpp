class Solution {
public:



    int openLock(vector<string>& deadends, string target) {
       
        set<string>deadend;
        for(string i : deadends){
            if(i == "0000")return -1;
            deadend.insert(i);
        }
        
        queue<string>q;
        string curr = "0000";
        if(curr == target)return 0;
        q.push(curr);
        set<string>visited;
        visited.insert(curr);
        int turns = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int k = 0 ; k < sz ; k++){
                curr = q.front();
                q.pop();
                if(curr == target) return turns;

                for(int i = 0 ; i < 4 ; i++){

                    char orig = curr[i];
                    //+1
                    curr[i] = (orig=='9')?'0' : orig + 1;
                    if(!deadend.count(curr) and !visited.count(curr)){
                        visited.insert(curr);
                        q.push(curr);
                    }

                    //-1
                    curr[i] = (orig=='0')?'9' : orig - 1;
                    if(!deadend.count(curr) and !visited.count(curr)){
                        visited.insert(curr);
                        q.push(curr);
                    }
                    curr[i] = orig;

                }


            }
                turns++;
        }


            return -1;


        }
        

    
};
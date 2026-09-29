class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R,D;
        int n = senate.size();

        for(int i = 0; i < n;i++){
            if(senate[i] == 'R')R.push(i);
            else D.push(i);
        }

        while(!R.empty() and !D.empty()){
            int rindex = R.front(); R.pop();
            int dindex = D.front(); D.pop();

            if(rindex < dindex){
                R.push(rindex + n);
            }
            else D.push(dindex + n);
        
        }
        //if r queue is empty that means dire wins
        return R.empty() ? "Dire": "Radiant";
    }
};
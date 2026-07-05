class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int>wallet(3,0);
        for(int i : bills){
            if(i==5){
                wallet[0]++;
            }
            
            
            if(i==10){    
                wallet[1]++;
                if(wallet[0]){wallet[0]--;continue;}
                else return false;
            }
            
            if(i==20){
                if(wallet[1] and wallet[0]){wallet[1]--;wallet[0]--;continue;}
                else if(wallet[0]>=3){
                    wallet[0]=wallet[0]-3;
                    continue;
                }
                else return false;  
                 wallet[2]++;
                 
                 }

        }
                 return true;


        
    }
};
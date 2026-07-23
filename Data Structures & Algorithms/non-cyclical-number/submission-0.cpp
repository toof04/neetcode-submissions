class Solution {
public:
    bool isHappy(int n) {
        int sum = 0; 
        vector<int>found(1000,0);
        while(n!=1){
            sum=0;
        while(n){
            int dig = n%10;
            sum+= dig*dig;
            n/=10;
            
        }
        n=sum;
            if(!found[sum])found[sum]=1;
            else return false;
        }
        return true;

    }
};

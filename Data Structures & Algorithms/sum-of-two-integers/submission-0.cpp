class Solution {
public:
    int getSum(int a, int b) {
        //xor gives sum without carry
        //& gives carry, <<1 shifts it to right place where it will add up
        while(b!=0){
            int carry  = (a&b)<<1;
            a = a^b; 
            b = carry;
        }
        return a;
    }
};

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x!=0){
            int dig = x%10;
            x/=10;

            //max overflow
            if(rev > INT_MAX / 10 or (rev == INT_MAX/10 and dig > 7))return 0;
            //min overflow
            if(rev < INT_MIN / 10 or (rev == INT_MIN/10 and dig < -8 ))return 0;


            rev = rev * 10 + dig;

        }
        return rev;
    }
};

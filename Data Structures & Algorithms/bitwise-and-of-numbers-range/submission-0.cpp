class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int change = 0;
        while(left!=right){
            left>>=1;
            right>>=1;
            change++;
        }
        return left << change;
    }
};
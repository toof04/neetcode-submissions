class Solution {
public:
    bool checkValidString(string s) {
        int leastunmatched = 0;
        int mostunmatched = 0;
        for(char c : s){
            if(c=='('){
                leastunmatched++;
                mostunmatched++;
            }
            else if(c==')'){
                leastunmatched--;
                mostunmatched--;
            }
            else{
                leastunmatched--;
                mostunmatched++;
            }
            if(mostunmatched < 0){
                return false;
            }
            if(leastunmatched < 0)leastunmatched=0;
        }
        return leastunmatched==0;

    }
};

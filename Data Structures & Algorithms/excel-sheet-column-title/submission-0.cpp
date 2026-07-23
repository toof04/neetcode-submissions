class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        while(columnNumber){
            columnNumber--;
            char a = columnNumber%26 + 65;
            s+= a;
            columnNumber/=26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.length();
        if(n<2)return s;
        int start = 0;
        int maxlength = 1;
        for(int i = 0; i < n; i++){
            //odd-length
            expand(s,i,i,start,maxlength);
            //even-length
            expand(s,i,i+1,start,maxlength);
        }
        return s.substr(start,maxlength);
    }
private:
    void expand(string &s, int left, int right, int &start, int&maxlength){
        while(left>=0 and right<s.length() and s[left]==s[right]){
            int currlength = right-left+1;
            if(currlength>maxlength){
                maxlength=currlength;
                start = left;
            }
                    left--;
        right++;
        }

    }
};

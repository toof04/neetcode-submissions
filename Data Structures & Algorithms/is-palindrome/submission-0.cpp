class Solution {
public:

    char convert( char a){
        if((int)a >= (int)'A' and (int)a<=(int)'Z') return a - 'A' + 'a';
        return a;
    }

    bool specialChar(char a){
    return (a >= 'a' && a <= 'z') ||
           (a >= 'A' && a <= 'Z') ||
           (a >= '0' && a <= '9');
    }

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i<j){
            
            if(!specialChar(s[i])){i++;continue;}
            if(!specialChar(s[j])){j--;continue;}

            if(convert(s[i])!=convert(s[j]))return false;
            i++;
            j--;

        }

        return true;
    }
};

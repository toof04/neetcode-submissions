class Solution {
public:

    bool normalpalindrome(string s, int left, int right){
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool atmostpalindrome(string s, int left, int right, int skip){
        while(left<=right){
            if(left==skip)left++;
            if(right==skip)right--;
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }


    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;
        int skip = 0;
        bool a = normalpalindrome(s,left,right);
        if(a)return true;
        bool b = false;
        for(;skip<=right;skip++){
            bool b = atmostpalindrome(s,left,right,skip);
            cout<<b<<" "<<skip<<" - ";
            if(b)return true;
        }

        return false;
        
    }
};
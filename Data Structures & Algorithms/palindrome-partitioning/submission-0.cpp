class Solution {
public:

    bool ispalindrome(string& s, int left, int right){
        while(left < right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void backtrack( string &s, int start, vector<string>&curr, vector<vector<string>>&result){
    if(start == s.length()){
        result.push_back(curr); return;
    }
    for(int end = start; end < s.length(); end++){
        //if not palindrome then continue;
        if(!ispalindrome(s , start ,end))continue;
        //include
            curr.push_back(s.substr(start, end - start +1));
        //explore
            backtrack(s, end+1, curr, result);
        //exclude
            curr.pop_back();
    }
    
    
    }



    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string>curr;
        backtrack(s, 0 , curr, result);
        return result;

    }
};

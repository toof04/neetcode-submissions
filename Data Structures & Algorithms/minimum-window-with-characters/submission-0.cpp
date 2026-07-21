class Solution {
public:

    string minWindow(string s, string t) {
        vector<int>need(128,0);
        int required = 0;
        for(char i :t){
            need[i]++;
            required++;
        }
        int l = 0;
        int r = 0;
        int minimum = INT_MAX;
        int start = 0;
        for(; r<s.length();r++){
            if(need[s[r]] > 0){
                required--;
            }
            need[s[r]]--;
            while(required==0){
                if(r-l+1<minimum){
                    start = l;
                    minimum = r - l + 1;
                }
                need[s[l]]++;

                if(need[s[l]]>0)required++;

                l++;
            }
        }
            if(minimum==  INT_MAX)return "";
        return s.substr(start, minimum);
        }
};

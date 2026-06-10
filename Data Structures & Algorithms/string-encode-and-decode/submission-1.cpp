class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for (string str : strs){
                s = s + str + "\n";
            }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string str = "";
        for (char cha : s){
            if(cha == '\n'){
                ans.push_back(str);
                str = "";
                continue;
                }
            str += cha;
        }
        return ans;
    }
};

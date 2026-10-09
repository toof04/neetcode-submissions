class Solution {
public:
    string simplifyPath(string path) {
        string curr = "";
        vector<string>dir;
        for(char c : path + "/"){
            if(c=='/'){
                if (curr == ".."){ if(!dir.empty())dir.pop_back();}
                else if (!curr.empty() and curr!=".")dir.push_back(curr);
                curr="";
            }
            else curr+=c;
        }

        string result = "/";
        for (int i = 0; i < dir.size(); ++i) {
            if (i > 0) result += "/";
            result += dir[i];
        }

        return result;
    }
};
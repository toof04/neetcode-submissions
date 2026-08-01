class Solution {
public:
    string simplifyPath(string path) {
        string curr = "";
        vector<string>dir;
        path = path + '/';
        for(int i = 1 ; i < path.length(); i++){
            char c = path[i];
            if(c == '/'){
                  if(curr == ".."){
                    if(!dir.empty())dir.pop_back();
                  } else if(!curr.empty() and curr!="."){
                        dir.push_back(curr);
                  }
                  curr.clear();  
            }
            else curr+=c;
        }

        string result = "/";
        for(int i = 0 ; i < dir.size(); i++){
            if(i>0)result += "/";
            result += dir[i];
        }
        return result;
    }
};
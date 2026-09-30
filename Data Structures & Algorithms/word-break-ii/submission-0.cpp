class Solution {
public:
vector<string>answer;
string question;
vector<string>wordDict;
    void recurse(int index, string currentstring){
        if(index == question.size()){
            answer.push_back(currentstring);
        }
        for(int j = 0; j < wordDict.size(); j++){
           string word = wordDict[j];
           if(question.substr(index, word.size()) == word){
            //word is the one needed to be inserted
            string next = currentstring;
            if(!next.empty())next+=" ";
            next+=word;
            recurse(index + word.size(),next);
           }
        }
    }


    vector<string> wordBreak(string s, vector<string>& wordDict1) {
        wordDict = wordDict1;
        string currentstring = "";
        question = s;
        recurse(0,currentstring);
        return answer;
    }
};
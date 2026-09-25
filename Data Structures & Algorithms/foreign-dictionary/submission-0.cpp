class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        //creating the adjacency matrix
        unordered_map<char,unordered_set<char>>adj;
        unordered_map<char,int>indegree;
        //intializing because there maybe some single letter words
        for(auto word : words){
            for(char c : word){
                adj[c] = {};
                indegree[c] = 0;
            }
        }
        for(int i = 0; i < words.size()-1 ; i++){
            string w = words[i];
            string w2 = words[i+1];
            int shorter = min(words[i].size() , words[i+1].size());
            //ab will come before abc
            if(w.size() > w2.size() and w.substr(0,shorter)==w2.substr(0,shorter) )return "";
            for(int j = 0; j <shorter; j++){
                
                if(w[j]==w2[j])continue;//if same char in both words then skip
                //check to see if the adj matrix already has that letter 
                // if not,then we add
                if(!adj[w[j]].count(w2[j])){
                    adj[w[j]].insert(w2[j]);
                    indegree[w2[j]]++;
                }
                break; //break at the first difference, as its not necessary the later char is 'after' to the first word's char
            }
        }

        queue<char> q;
        //kahns pushing indegree zero to queue
        for(auto i : indegree){
            if(i.second == 0)q.push(i.first);
        }

        string res = "";

        while(!q.empty()){
            char front = q.front();
            q.pop();
            res+=front;
            for(auto i : adj[front]){
                indegree[i]--;
                if(indegree[i]==0)q.push(i);

            }
        }

        return res.size() == indegree.size() ? res : "";



    }
};

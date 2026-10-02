class Solution {
public:
    int ladderLength(string beginword, string endword, vector<string>& wordlist) {
        //if endword is not in the list or beginword and endwords are same then return 0
        if(find(wordlist.begin(), wordlist.end(), endword)==wordlist.end() or beginword == endword) return 0;

        //making adjacency matrix where two words are connected when only one character is different b/w the words

        int n = wordlist.size();
        int wordlength = wordlist[0].length();
        vector<vector<int>>adj(n);

        for(int i = 0 ; i < n; i++){
            for(int j = i + 1; j < n; j++){
                    int diff = 0;
                    for(int k = 0; k < wordlength; k++){
                        if (wordlist[i][k]!=wordlist[j][k])diff++;
                    }
                if(diff==1){ //if difference between words is exactly one character
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        queue<int>q;
        vector<bool>visited(n,false);

        //finding words with only one difference to beginning word
        for(int i = 0; i < n ; i++){
            int diff = 0;
            for(int k = 0 ; k < wordlength; k++){
                if(wordlist[i][k]!=beginword[k])diff++;
            }
            if(diff==1){
                q.push(i);
                visited[i] = true;
            }
        }

        int turns = 2;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front();
                q.pop();
                if(wordlist[node]==endword)return turns;
                for(int neighbor : adj[node]){
                    if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = true;
                    }
                }
            }
            turns++;
        }
        return 0;



    }
};

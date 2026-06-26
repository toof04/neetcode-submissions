class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>hash(26);
            for(int i = 0; i<order.size();i++){
                hash[order[i]-'a']=i;
            }
            int n = words.size();
            for(int i = 0; i<n-1;i++){
                int min_len = min(words[i].size(),words[i+1].size());
                int j = 0;
                while(j<min_len && words[i][j]==words[i+1][j])j++;

                if(j==min_len){
                    if (words[i+1].size()<words[i].size())return false;
                }
                else if(hash[words[i][j] - 'a']>hash[words[i+1][j] - 'a'])return false;

            }

return true;
    }
};
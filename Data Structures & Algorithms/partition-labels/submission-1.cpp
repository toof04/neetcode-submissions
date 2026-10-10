class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>last;
        for(int i = 0;i<s.length();i++){
            last[s[i]]=i;
        }

        vector<int>sizes;
        int size = 0;
        int currend = 0;
        for(int i = 0;i<s.length();i++){
            currend = max(currend, last[s[i]]);
            size++;
            if(i==currend){
                sizes.push_back(size);
                size = 0;
            }
        }
        return sizes;
    }
};

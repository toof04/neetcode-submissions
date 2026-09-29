class Solution {
public:
    vector<int> partitionLabels(string s) {
        //calculate last index of every character
        unordered_map<char, int>last;
        for(int i =0 ; i < s.size();i++){
            last[s[i]]=i;
        }

        vector<int>sizes;
        int size = 0;
        int end = 0;
        for(int i = 0; i < s.size(); i++){
            size++;
            end = max(end, last[s[i]]);
            if(i == end){
                sizes.push_back(size);
                size = 0;
            }
        }
        return sizes;
    }
};

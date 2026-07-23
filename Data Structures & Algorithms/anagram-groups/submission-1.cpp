class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>sum;
        for(int i = 0;i<strs.size();i++){
            vector<int>indsum(26,0);            
            for(int j = 0;j<strs[i].length();j++){
                indsum[strs[i][j] - 'a']++;
            }
            sum[indsum].push_back(strs[i]);
        }
        vector<vector<string>>answer;
        for(auto i = sum.begin(); i!=sum.end();i++){
            answer.push_back(i->second);
            }
        
        return answer;


    }
};
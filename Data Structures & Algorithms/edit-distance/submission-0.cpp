class Solution {
public:
vector<vector<int>>dp;
    int recurse(const string &word1, const string &word2, int i , int j){
        //base
        if (i == word1.size()){
            return word2.size() - j;
        }
        if (j == word2.size()){
            return word1.size() - i;
        }

        if(dp[i][j]!=-1)return dp[i][j];
        //match
        if(word1[i] == word2[j])return dp[i][j]=recurse(word1,word2,i+1,j+1);
        //replace
        int replace = recurse(word1,word2,i+1,j+1);
        //insert
        int insert = recurse(word1,word2,i,j+1);
        //delete
        int deleted =  recurse(word1,word2,i+1,j);

        //return min
        return dp[i][j]= 1 + min(replace, min(insert, deleted));
    }



    int minDistance(string word1, string word2) {
        dp.assign(word1.size()+1, vector<int>(word2.size()+1, -1));
        return recurse(word1,word2,0,0);
    }
};

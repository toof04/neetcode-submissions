class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a = target[0];
        int b = target[1];
        int c = target[2];

        int amax = 0 , bmax = 0, cmax = 0;

        for(int i = 0; i < triplets.size(); i++){
            if (triplets[i][0] > a or triplets[i][1] > b or triplets[i][2] > c)continue;
            amax = max(amax, triplets[i][0]);
            bmax = max(bmax, triplets[i][1]);
            cmax = max(cmax, triplets[i][2]);
        }
        if(amax == a and bmax == b and cmax == c)return true;
        return false;
    }
};

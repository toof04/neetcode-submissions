class Solution {
public:
vector<vector<int>>dp;
    int solve(vector<int>& piles, int left, int m) {
        if (left >= piles.size())
            return 0;

        if(dp[left][m]!=INT_MIN)return dp[left][m];
        int answer = INT_MIN;
        int pilesum = 0;

        for (int x = 1; x <= 2 * m && left + x - 1 < piles.size(); x++) {
            pilesum += piles[left + x - 1];
            int candidate = pilesum - solve(piles, left + x, max(m, x));

            answer = max(answer, candidate);
        }

        return dp[left][m] = answer;
    }

    int stoneGameII(vector<int>& piles) {
        dp.assign(piles.size()+1, vector<int>(2*piles.size()+1, INT_MIN ));
        int diff =  solve(piles, 0, 1);
        int totalsum = accumulate(piles.begin(), piles.end(), 0);
        return (diff+totalsum)/2;
    }
};
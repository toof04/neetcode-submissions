class Solution {
public:

    int check(vector<int>&piles, int mid){
        int h = 0;
        
        for(int i = 0; i < piles.size();i++){
           h+=(piles[i] + mid - 1)/mid;
        }
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int l = 1, r = *max_element(piles.begin(),  piles.end());
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(piles, mid)<=h)r = mid-1;
            else l = mid+1;
        }
        return l;

    }
};

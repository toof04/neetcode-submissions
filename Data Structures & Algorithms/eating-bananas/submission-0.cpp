class Solution {
public:
    
    int calculat(vector<int>&piles, int mid){
        int count = 0;
        for(int i = 0; i<piles.size();i++){
            count+= (piles[i] + mid - 1)/mid;
        }
        return count;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());;
                while(left<right){
            int mid = left + (right-left)/2;
            if(calculat(piles,mid)<=h){right = mid;}
            else left=mid+1;
        }
        return left;
    }
};

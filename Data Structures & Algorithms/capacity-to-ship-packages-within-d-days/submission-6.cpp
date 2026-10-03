class Solution {
public:
    int check(vector<int>& weights, int mid){
               int count = 1;
        int currpack = 0;
        for(int w = 0; w< weights.size();w++){
            if(currpack + weights[w] <= mid){
                currpack +=weights[w];
            }
            else {
                count++;
                currpack = 0;
                w--;
            }
            if(currpack == 0 and currpack+weights[w]>mid)return -1;
        }
        return count;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(),0);
        while(l<=r){
            int mid = l + (r-l)/2;
            if (check(weights,mid) <= days)r = mid-1;
            else l = mid+1;
        }
        return l;
    }
};
class Solution {
public:
    int calc(vector<int>&weights, int days, int mid){
        int count = 1;
        int currpack = 0;
        for(int w = 0; w< weights.size();w++){
            if(count>days)return -1;
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
        int m = accumulate(weights.begin(),weights.end(),0);
        // vector<int>vals;
        // for(int i = 0; i<m;i++){
        //     vals.push_back(i);
        // }
        int left = *max_element(weights.begin(),weights.end());
        int right = m;
        int ans = m;
        while(left<right){
            int mid = left + (right-left)/2;
            int curr = calc(weights, days, mid);
            if(curr!=-1 and curr<=days){
                right = mid;
            }
            else{
                left = mid+1;
            }

        }
        return left;
    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size() - 1;
        while(r-l+1>k){
            if(abs(arr[r]-x) < abs(arr[l]-x)){
                l++;
            }
            else r--;
        }
        vector<int>result(arr.begin() + l, arr.begin() + r+1);
        return result;
    }
};
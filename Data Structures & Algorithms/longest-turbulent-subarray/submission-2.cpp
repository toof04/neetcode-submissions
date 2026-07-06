class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int curr = 1;
        int maxi = 1;
        bool peak = true;
         vector<int>peaks;
        peaks.push_back(0);
       
        for(int i = 1; i<arr.size(); i++){
            if(arr[i-1]>arr[i]){peaks.push_back(1);}
            else if (arr[i-1]<arr[i]) peaks.push_back(-1);
            else peaks.push_back(0);
        }
        for(int i = 1; i<arr.size();i++){
            if(peaks[i]==0)curr=1;
            else if(peaks[i]==peaks[i-1])curr = 2;
            else curr++;

            maxi=max(maxi,curr);
        }




        return maxi;
    }
};
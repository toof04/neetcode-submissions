class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i,j,write;
        i = m-1;
        j = n-1;
        write = m+n-1;
        while(j>=0){
                if(i>=0 and nums1[i]>=nums2[j]){
                    nums1[write] = nums1[i];
                    i--;
                }
                else{
                    nums1[write]=nums2[j];
                    j--;
                }    
                write--;           

        }
    }
};
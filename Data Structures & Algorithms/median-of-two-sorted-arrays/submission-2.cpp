class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())swap(nums1,nums2);
        
        int l = 0;
        int r = nums1.size();
        int total =nums1.size() + nums2.size();
        int half = total/2;
        
        while(l<=r){
            int i = (l + r)/2;
            int j = half - i;

            int Aleft = i == 0 ? INT_MIN: nums1[i-1];
            int Aright = i == nums1.size() ? INT_MAX : nums1[i];

            int Bleft = j==0? INT_MIN : nums2[j-1];
            int Bright = j == nums2.size()? INT_MAX : nums2[j];

            if(max(Aleft,Bleft) <= min(Aright, Bright)){
                if(total%2==1)return min(Aright,Bright);
                else return (max(Aleft, Bleft)+min(Aright,Bright))/2.0;
            }
            else if (Aleft > Bright){
                r = i-1;
            }else l = i+1;
            
        }
        return -1;
    
    }
};

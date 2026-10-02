class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int total = A.size() + B.size();
        //how many elements should be on one side
        int half = (total+1)/2;
        if(B.size() < A.size())
            swap(A,B);
        
        int l = 0;
        int r = A.size();

        // we are trying to have 4 pointers Aleft,Bleft,Aright,Bright and finding the correct position of left < right
        while(l<=r){
        int i = (l + r)/2; //iterator of A
        int j = half - i; //number of elements to be taken from B to have LEFT partition half of the total

        //these are all edge cases for selecting left / right partition of the arrays
        int Aleft = i>0 ?A[i-1]:INT_MIN;
        int Aright = i<A.size()? A[i]:INT_MAX;
        int Bleft = j>0?B[j-1]:INT_MIN;
        int Bright = j<B.size()?B[j]:INT_MAX;

        if(max(Aleft,Bleft) <= min(Aright,Bright)){ //we have found the correct partition as all elements of left < elements of right
            if(total%2!=0){ //odd elements so only one element is median
                return max(Aleft, Bleft); //max of left partition
            }
            return (max(Aleft, Bleft) + min(Aright, Bright))/2.0;
        }
        else if (Aleft > Bright){
            //left is on the smaller side 
            r = i -1;
        }else l = i+1;

        }
        return -1;
    }
};

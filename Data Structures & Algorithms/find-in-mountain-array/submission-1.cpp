/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        //find peak
        int l = 1; //not 0 because we'll be checking l -1 and r + 1
        int r = arr.length()-2;
        int peak = 0;
        while(l<=r){
            int mid = l + (r-l)/2;

            int left = arr.get(mid-1);
            int middle = arr.get(mid);
            int right = arr.get(mid+1);
            if(left < middle and middle > right){
                peak = mid;
                break;
            }
            else if(left < middle and middle < right){
                l = mid + 1;
            }
            else{r = mid-1;}
        }
        l = 0;
        r = peak - 1;
        //search in left portion
        while (l<=r){
            int mid = l + (r-l)/2;
            int val = arr.get(mid);
            if(val == target)return mid;
            else if(val < target){
                l = mid + 1;
            }
            else r = mid - 1;
        }

        // search in right portion
        l = peak;
        r = arr.length() - 1;
        //search in left portion
        while (l<=r){
            int mid = l + (r-l)/2;
            int val = arr.get(mid);
            if(val == target)return mid;
            else if(val > target){
                l = mid + 1;
            }
            else r = mid - 1;
        }


        return -1;

    }
};
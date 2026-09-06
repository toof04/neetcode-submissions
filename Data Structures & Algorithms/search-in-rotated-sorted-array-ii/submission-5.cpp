class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        int pivot = n - 1;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        cout<<"Pivot : "<<pivot<<endl;
        auto it1 = lower_bound(nums.begin(), nums.begin() + pivot + 1,target);

        if (it1 != nums.begin() + pivot + 1 and *it1 == target) {
            return true;
        }
        auto it2 = lower_bound(nums.begin() + pivot + 1,nums.end(),target);

        if (it2 != nums.end() and *it2 == target) {
            return true;
        }

        return false;
    }
};
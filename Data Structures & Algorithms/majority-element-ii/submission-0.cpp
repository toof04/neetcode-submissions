class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        long long first = LLONG_MAX;
        int firstfreq = 0;
        long long second = LLONG_MAX;
        int secondfreq = 0;    
        for(int i = 0; i<nums.size();i++){
            if(nums[i]==first)firstfreq++;
            else if(nums[i]==second)secondfreq++;
            else if (firstfreq==0){first=nums[i];firstfreq=1;}
            else if (secondfreq==0){second=nums[i];secondfreq=1;}
            else {firstfreq--;secondfreq--;}

        }
        firstfreq=secondfreq=0;
        for(int num :nums){
            if(num == first)firstfreq++;
            else if(num == second)secondfreq++;
        }
        vector<int>res;
        if(firstfreq>nums.size()/3)res.push_back(first);
        if(secondfreq>nums.size()/3)res.push_back(second);
        return res;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;

        while(i<j){
            int currsum = numbers[i] + numbers[j];

            if(currsum<target)i++;
            else if(currsum>target)j--;
            else return {i+1,j+1};

            
        }   
        
        return {i+1,j+1};
        
    }
};

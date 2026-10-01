class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int>ans(num1.size() + num2.size(), 0);   // fixed size, all zeros
        int carry = 0;
        
        for(int i = num2.length()-1; i>=0;i-- ){          // i >= 0
            int sum = 0;
            carry = 0;                                     // reset carry for each row
            for(int j = num1.length()-1 ; j>=0 ; j--){     // use j, not i
                    sum = (num1[j]-'0') * (num2[i]-'0') + ans[i+j+1] + carry;  // multiply, add what's already there
                    ans[i+j+1] = sum%10;                   // store at the right position
                    carry = sum/10;
            }
            ans[i] += carry;                               // leftover carry
        }
    
        string res = "";                                   // build result string
        for(int d : ans){
            if(res.empty() && d == 0) continue;            // skip leading zeros
            res += (d + '0');
        }
        return res.empty() ? "0" : res;
    }
};
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        
        for(string str : tokens){
            
            if(str=="+" or str=="-" or str=="*" or str=="/"){
                int temp = s.top();
                s.pop();
                int temp2 = s.top();
                s.pop();
                if      (str == "+") s.push(temp2 + temp);
else if (str == "-") s.push(temp2 - temp);
else if (str == "*") s.push(temp2 * temp);
else if (str == "/") s.push(temp2 / temp);
                

            }
            else s.push(stoi(str));

        }
        if(!s.empty())return s.top();
        return -1;
    }
};

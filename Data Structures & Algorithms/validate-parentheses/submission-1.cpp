class Solution {
public:
    bool isValid(string s) {
        stack<char>q;
        for(char a : s){
            if(a=='(' or a=='{' or a=='[')q.push(a);
            else{
                if(q.empty())return false;
                
                if(a==')' and q.top()=='(')q.pop();
                else if(a=='}' and q.top()=='{')q.pop();
                else if(a==']' and q.top()=='[')q.pop();
                else return false;
            }
        }
        if(q.empty())return true;
        return false;
    }
};

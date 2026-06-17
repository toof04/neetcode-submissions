class Solution {
public:
    string decodeString(string str) {
     stack<string>s;
     stack<int>n;

     
        int num = 0;
        string current = "";
        for(char st : str){
            if (isdigit(st))num=num*10 + (st-'0');
            else if(st == '['){
                n.push(num);
                s.push(current);
                num = 0;
                current = "";
            }
            else if(st == ']'){
                int repeat = n.top();
                string prev = s.top();
                n.pop(); s.pop();
                string after = "";
                for(int i = 0; i<repeat;i++){
                    after+=current;
                }
                current = prev + after;
            }
            else current+=st;
        }
        return current;}
};
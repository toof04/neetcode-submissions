class Solution {
public:
    string decodeString(string str) {
       stack<string>s;
       stack<int>n;
       int num = 0;
       string curr = "";
       for(char c : str){
            if(isdigit(c))num=num*10 + (c-'0');
            else if(c == '['){
                n.push(num);
                s.push(curr);
                num = 0;
                curr = "";
            }
            else if (c==']'){
                int repeat = n.top();
                string prev = s.top();
                n.pop(); s.pop();
                string after = "";
                for(int i = 0; i < repeat; i++)after+=curr;
                curr = prev+after;                              
            }
            else curr +=c;
       }
       return curr; 
    }
};